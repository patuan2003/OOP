#include<bits/stdc++.h>
using namespace std;

class Date{
	private:
		int d, m, y;
	
	public:
		void nhap(){
			cout << "Nhap ngay: ";
			cin >> d;	
			cout << "Nhap thang: ";
			cin >> m;
			cout << "Nhap nam: ";
			cin >> y;
		}
		
		void xuat(){
			cout << d << "/" << m << "/" << y << endl;
		}
};

class XeHoi{
	private:
		char hangSX[20];
		Date namSX;
		float giaBan;
		int soLuongBan;
	
	public: 
		void nhap(){
			cout << "Nhap hang san xuat: ";
			fflush(stdin); gets(hangSX);
			cout << "Nhap nam san xuat: " << endl;
			namSX.nhap();
			cout << "Nhap gia ban: ";
			cin >> giaBan;
			cout << "Nhap so luong ban: ";
			cin >> soLuongBan;
		};
		
		void xuat(){
			cout << "Xuat thong tin xe hoi: " << endl;
			cout << "Hang san xuat: " << hangSX << endl;
			cout << "Nam san xuat: ";
			namSX.xuat();
			cout << "Gia ban: " << giaBan << endl;
			cout << "So luong ban: " << soLuongBan << endl;
		};
};

int main(){
	XeHoi xh;
	xh.nhap();
	xh.xuat();
	return 0;
}
