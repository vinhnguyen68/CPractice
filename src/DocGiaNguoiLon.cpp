#include "DocGiaNguoiLon.h"

DocGiaNguoiLon::~DocGiaNguoiLon(void){}

DocGiaNguoiLon::DocGiaNguoiLon(void){
    CMND = "0";
}

ostream& operator << (ostream& os, DocGiaNguoiLon& obj){
    DocGia& cha = static_cast<DocGia&>(obj);  
    os << cha;
    os << endl << "Nguoi dai dien: " << obj.CMND;
    return os;
}

istream& operator >> (istream& is, DocGiaNguoiLon& obj){
    DocGia& cha = static_cast<DocGia&>(obj);  
    is >> cha;
    fflush(stdin);
    cout << "Nhap so CMND: ";
    getline(is, obj.CMND);
    return is;
}

string DocGiaNguoiLon::getCMND() const { return CMND; }

void DocGiaNguoiLon::setCMND(const string& newCMND){
    CMND = newCMND;
}

float DocGiaNguoiLon::TinhTienLamThe(){
    return SoThangHieuLuc * 10000;
}


