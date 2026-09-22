#pragma once
#include <iostream>
#include "DocGia.h"
using namespace std;

class DocGiaTreEm : public DocGia{
    private:
        string HoTenNguoiDaiDien;
    public:
        friend ostream & operator << (ostream& os, DocGiaTreEm& obj);
        friend istream & operator >> (istream& is, DocGiaTreEm& obj);
        DocGiaTreEm();
        ~DocGiaTreEm();
        float TinhTienLamThe(void){
            return 20000;
        }
};