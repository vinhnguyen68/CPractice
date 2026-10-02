#pragma once
#include <iostream>
using namespace std;

class Ngay{
    private:
        int ngay;
        int thang;
        int nam;
    public:
        friend istream& operator >> (istream &, Ngay&);
        friend ostream& operator << (ostream &, Ngay&);
        Ngay(void);
        ~Ngay(void);

        int getNgay() const;
        int getThang() const;
        int getNam() const;
};

