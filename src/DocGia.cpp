#include "DocGia.h"

istream& operator >>(istream &is, DocGia &x)
{
	fflush(stdin); // Xóa bộ nhớ đệm
	cout << "\nNhap vao ho ten: ";
	getline(is, x.HoTen);

	cout << "\nNhap vao ngay lap the: ";
	is >> x.NgayLapThe;

	do{
		cout << "\nNhap vao so thang co hieu luc: ";
		is >> x.SoThangHieuLuc;

		if(x.SoThangHieuLuc <= 0)
		{
			cout << "\nSo thang co hieu luc phai la so duong khac 0. Xin kiem tra lai !";
		}
	}while(x.SoThangHieuLuc <= 0);

	return is;
}

ostream& operator <<(ostream &os, DocGia x)
{
	os << "\nHo ten: " << x.HoTen;
	os << "\nNgay lap the: " << x.NgayLapThe;
	os << "\nSo thang co hieu luc: " << x.SoThangHieuLuc;

	return os;
}

DocGia::DocGia(void)
{
}


DocGia::~DocGia(void)
{
}
