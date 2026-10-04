#pragma once
#include <iostream>
#include "DocGiaTreEm.h"
#include "DocGiaNguoiLon.h"
using namespace std;

class ThuVien{
    private:
        vector<DocGiaTreEm> ListDGTE;
        vector<DocGiaNguoiLon> ListDGNL;
    public:
        friend ostream& operator << (ostream& os, ThuVien& obj);
        friend istream& operator >> (istream& is, ThuVien& obj);
        ThuVien();
        ~ThuVien();
        float TinhTongTienLamThe();
        bool KiemTraTrungCMND(const string& cmnd);

        void ThemDocGiaNguoiLon(const DocGiaNguoiLon& dg);
        vector<DocGiaNguoiLon> LayDanhSachNguoiLon() const;
        DocGiaNguoiLon* TimTheoCMND(const string& cmnd);
        bool XoaTheoCMND(const string& cmnd);
};
