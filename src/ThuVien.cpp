#include "ThuVien.h"

ThuVien::ThuVien(){}

ThuVien::~ThuVien(){}

ostream& operator << (ostream& os, ThuVien& obj){
    os << "\n---------Danh Sach Doc Gia Tre Em---------------";
    int sizetreem = obj.ListDGTE.size();
    for (int i = 0; i < sizetreem; i++){
        os << "\nDoc gia thu " << i + 1 << obj.ListDGTE[i];
    }

    os << "\n---------Danh Sach Doc Gia Nguoi Lon------------";
    int sizenguoilon = obj.ListDGNL.size();
    for (int i = 0; i < sizenguoilon; i++){
        os << "\nDoc gia thu " << i + 1 << obj.ListDGNL[i];
    }

    return os;
}


istream& operator >> (istream& is, ThuVien& obj){
    int luachon;
    do{
        cout << "\n-----------Menu------------\n";
        cout << "\n1. Doc Gia Tre Em";
        cout << "\n2. Doc Gia Nguoi Lon";
        cout << "\n3. Thoat";
        cout << "\n---------------------------\n";

        do{
            cout << "Nhap vao lua chon cua ban: ";
            is >> luachon;
            if (luachon < 1 || luachon > 3){
                cout << "Lua chon khong hop le nhap lai";
            }

        }while(luachon < 1 || luachon >3);

        if (luachon == 1){
            DocGiaTreEm a;
            is >> a;
            obj.ListDGTE.push_back(a);
        }

        else if (luachon == 2){
            DocGiaNguoiLon a;
            is >> a;
            obj.ListDGNL.push_back(a);
        }

    }while(luachon != 3);
    return is;
}



float TinhTongTienLamThe(){
    return 100000;
}
