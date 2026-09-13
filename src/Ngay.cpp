#include "Ngay.h"

istream& operator >> (istream &is, Ngay &x){
    cout  << "\nNhap vao ngay: ";
    is >> x.ngay;

    cout  << "\nNhap vao thang: ";
    is >> x.thang;

    cout  << "\nNhap vao nam: ";
    is >> x.nam;

    return is;
}

ostream& operator << (ostream &os, Ngay &x){
        os << "Ngay " << x.ngay << "Thang" << x.thang << "Nam" << x.nam;
        return os;
}

Ngay::Ngay(void){

}

Ngay::~Ngay(void){

}