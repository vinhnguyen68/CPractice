#pragma once
#include <iostream>
#include "DocGia.h"
using namespace std;

class DocGiaNguoiLon : public DocGia{
    private:
        string CMND;
    public:
        friend ostream & operator << (ostream& os, DocGiaNguoiLon& obj);
        friend istream & operator >> (istream& is, DocGiaNguoiLon& obj);
        DocGiaNguoiLon();
        ~DocGiaNguoiLon();
        string getCMND() const;
        void setCMND(const string& newCMND);
        float TinhTienLamThe() override;
};