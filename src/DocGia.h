#pragma once
#include "Ngay.h"
#include <string>

// Lớp cha
class DocGia
{
protected:
	string HoTen;
	CNgay NgayLapThe;
	int SoThangHieuLuc;
public:
	friend istream& operator >>(istream &, DocGia &);
	friend ostream& operator <<(ostream &, DocGia);
	DocGia(void);
	~DocGia(void);
};
