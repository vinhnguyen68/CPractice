#pragma once
#include "Ngay.h"
#include <string>

// Lớp cha
class DocGia
{
protected:
	string HoTen;
	Ngay NgayLapThe;
	int SoThangHieuLuc;
public:
	friend istream& operator >>(istream &, DocGia &);
	friend ostream& operator <<(ostream &, DocGia &);
	DocGia(void);
	~DocGia(void);
	virtual float TinhTienLamThe() = 0;

	// add setter getter for API
	string getHoTen() const;
	void setHoTen(const string& newHoTen);
	Ngay getNgayLapThe() const;
	void setNgayLapThe(const Ngay& newNgay);
	int getSoThangHieuLuc() const;
	void setSoThangHieuLuc(const int newSoThang);
};
