#include "DocGiaTreEm.h"

DocGiaTreEm::DocGiaTreEm(void){
    HoTenNguoiDaiDien = "";
}

DocGiaTreEm::~DocGiaTreEm(void){}

ostream& operator << (ostream& os, DocGiaTreEm& obj){
    DocGia& cha = static_cast<DocGia&>(obj);  
    os << cha;
    os << endl << "Nguoi dai dien: " << obj.HoTenNguoiDaiDien;
    os << endl << "Tien lam the: " << obj.TinhTienLamThe();
    return os;
}

istream& operator >> (istream& is, DocGiaTreEm& obj){
    DocGia& cha = static_cast<DocGia&>(obj);  
    is >> cha;
    fflush(stdin);
    cout << "Nhap ten nguoi dai dien: ";
    getline(is, obj.HoTenNguoiDaiDien);
    return is;
}




