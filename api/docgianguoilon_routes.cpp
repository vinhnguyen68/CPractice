#include "docgianguoilon_routes.h"
#include <string>

using namespace std;

namespace {
    string DocGiaNguoiLonToJson(DocGiaNguoiLon& dg) {
        Ngay ngay = dg.getNgayLapThe();
        return "{"
            "\"hoten\":\"" + dg.getHoTen() + "\","
            "\"cmnd\":\"" + dg.getCMND() + "\","
            "\"sothanghieuluc\":" + to_string(dg.getSoThangHieuLuc()) + ","
            "\"ngaylapthe\":{"
                "\"ngay\":" + to_string(ngay.getNgay()) + ","
                "\"thang\":" + to_string(ngay.getThang()) + ","
                "\"nam\":" + to_string(ngay.getNam()) +
            "},"
            "\"tienlamthe\":" + to_string(dg.TinhTienLamThe()) +
        "}";
    }
}

void RegisterDocGiaNguoiLonRoutes(httplib::Server& svr, ThuVien& thuVien) {

    // CREATE
    svr.Post("/docgianguoilon", [&thuVien](const httplib::Request& req, httplib::Response& res) {
        if (!req.has_param("cmnd") || !req.has_param("hoten") || !req.has_param("sothanghieuluc") ||
            !req.has_param("ngay") || !req.has_param("thang") || !req.has_param("nam")) {
            res.status = 400;
            res.set_content(R"({"error":"missing required field(s): cmnd, hoten, sothanghieuluc, ngay, thang, nam"})", "application/json");
            return;
        }

        string cmnd = req.get_param_value("cmnd");
        if (thuVien.KiemTraTrungCMND(cmnd)) {
            res.status = 409;
            res.set_content(R"({"error":"CMND already exists"})", "application/json");
            return;
        }

        try {
            DocGiaNguoiLon dg;
            dg.setCMND(cmnd);
            dg.setHoTen(req.get_param_value("hoten"));
            dg.setSoThangHieuLuc(stoi(req.get_param_value("sothanghieuluc")));
            dg.setNgayLapThe(Ngay(
                stoi(req.get_param_value("ngay")),
                stoi(req.get_param_value("thang")),
                stoi(req.get_param_value("nam"))
            ));

            thuVien.ThemDocGiaNguoiLon(dg);

            res.status = 201;
            res.set_content(DocGiaNguoiLonToJson(dg), "application/json");
        } catch (...) {
            res.status = 400;
            res.set_content(R"({"error":"invalid field value"})", "application/json");
        }
    });

    // READ (list all)
    svr.Get("/docgianguoilon", [&thuVien](const httplib::Request&, httplib::Response& res) {
        vector<DocGiaNguoiLon> list = thuVien.LayDanhSachNguoiLon();
        string body = "[";
        for (size_t i = 0; i < list.size(); i++) {
            if (i > 0) body += ",";
            body += DocGiaNguoiLonToJson(list[i]);
        }
        body += "]";
        res.set_content(body, "application/json");
    });

    // READ (one, by CMND in the URL path)
    svr.Get(R"(/docgianguoilon/([^/]+))", [&thuVien](const httplib::Request& req, httplib::Response& res) {
        string cmnd = req.matches[1];
        DocGiaNguoiLon* dg = thuVien.TimTheoCMND(cmnd);
        if (dg == nullptr) {
            res.status = 404;
            res.set_content(R"({"error":"reader not found"})", "application/json");
            return;
        }
        res.set_content(DocGiaNguoiLonToJson(*dg), "application/json");
    });

    // UPDATE
    svr.Put(R"(/docgianguoilon/([^/]+))", [&thuVien](const httplib::Request& req, httplib::Response& res) {
        string cmnd = req.matches[1];
        DocGiaNguoiLon* dg = thuVien.TimTheoCMND(cmnd);
        if (dg == nullptr) {
            res.status = 404;
            res.set_content(R"({"error":"reader not found"})", "application/json");
            return;
        }

        try {
            if (req.has_param("hoten")) {
                dg->setHoTen(req.get_param_value("hoten"));
            }
            if (req.has_param("sothanghieuluc")) {
                dg->setSoThangHieuLuc(stoi(req.get_param_value("sothanghieuluc")));
            }
            if (req.has_param("ngay") && req.has_param("thang") && req.has_param("nam")) {
                dg->setNgayLapThe(Ngay(
                    stoi(req.get_param_value("ngay")),
                    stoi(req.get_param_value("thang")),
                    stoi(req.get_param_value("nam"))
                ));
            }
            res.set_content(DocGiaNguoiLonToJson(*dg), "application/json");
        } catch (...) {
            res.status = 400;
            res.set_content(R"({"error":"invalid field value"})", "application/json");
        }
    });

    // DELETE
    svr.Delete(R"(/docgianguoilon/([^/]+))", [&thuVien](const httplib::Request& req, httplib::Response& res) {
        string cmnd = req.matches[1];
        bool removed = thuVien.XoaTheoCMND(cmnd);
        if (!removed) {
            res.status = 404;
            res.set_content(R"({"error":"reader not found"})", "application/json");
            return;
        }
        res.status = 204;
    });
}