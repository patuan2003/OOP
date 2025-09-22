#include<bits/stdc++.h>
using namespace std;

class CanBo{
	private:
		char maCanBo[10], hoTen[30];
		int namSinh;
		int soNgayLam;
		
	public:
		void nhap();
		float tinhLuong(){
			return soNgayLam * 250;
		};
		void xuat();
};

void CanBo::nhap(){
	cout << "Nhap ma can bo: ";
	gets(maCanBo);
	cout << "Nhap ho ten: ";
	gets(hoTen);
	cout << "Nhap nam sinh: ";
	cin >> namSinh;
	cout << "Nhap so ngay la viec: ";
	cin >> soNgayLam;
};

void CanBo::xuat(){
	cout << "Ma can bo: " << maCanBo << endl;
	cout << "Ho ten can bo: " << hoTen << endl;
	cout << "Nam sinh: " << namSinh << endl;
	cout << "Luong: " << tinhLuong() << endl;
}

int main(){
	CanBo cb;
	cb.nhap();
	cb.xuat();
}
