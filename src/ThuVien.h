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
        friend istream& operator >> (ostream& is, ThuVien& obj);
        ThuVien();
        ~ThuVien();
        float TinhTongTienLamThe();
};
