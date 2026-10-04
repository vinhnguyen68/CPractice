#include "docgianguoilon_routes.h"
#include <string>


namespace{
    float TinhTienLamThe(int soThangHieuLuc){
        return soThangHieuLuc * 10000;
    }
}

void RegisterDocGiaNguoiLonRoutes(httplib::Server& svr){
    svr.Get("/tinhtienlamthe", [](const httplib::Request& req, httplib::Response& res) {
        // check if the request has sothanghieuluc
        if (!req.has_param("sothanghieuluc")){
            res.status = 400;
            res.set_content(R"({"error":"missing sothanghieuluc parameters"})", "application/json");
            return;
        }
        // call the calculator, throw error if happen
        try{
            int soThang = std::stoi(req.get_param_value("sothanghieuluc"));
            float tien = TinhTienLamThe(soThang);
            std::string body = "{\"sothanghieuluc\":" + std::to_string(soThang) +
                        ",\"tien\":" + std::to_string(tien) + "}";
            res.set_content(body, "application/json");
        } catch(...){
            res.status = 400;
            res.set_content(R"({"error":"sothanghieuluc must be a valid integer"})", "application/json");
        }
    });
}