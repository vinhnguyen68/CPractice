#include "ThuVien.h"

ThuVien::ThuVien(){}

ThuVien::~ThuVien(){}

bool ThuVien::KiemTraTrungCMND(const string& cmnd){
    int sizeNguoiLon = ListDGNL.size();
    for (int i = 0; i < sizeNguoiLon; i++){
        if (cmnd == ListDGNL[i].getCMND()){
            return true;
        }
    }
    return false;
}

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
            bool duplicateCMND = false;
            do{
                duplicateCMND = obj.KiemTraTrungCMND(a.getCMND());
                if (duplicateCMND == false){
                    break;
                } 
                else{
                    cout << "CMND bi trung, nhap lai: ";
                    string newCMND = "";
                    fflush(stdin);
                    getline(is, newCMND);
                    a.setCMND(newCMND);
                }
            }while (duplicateCMND == true);
            obj.ListDGNL.push_back(a);
        }

    }while(luachon != 3);
    return is;
}



float ThuVien::TinhTongTienLamThe(){
    return 100000;
}
