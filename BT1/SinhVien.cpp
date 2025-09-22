#include<bits/stdc++.h>
using namespace std;

class hocSinh{
	private:	
		char hoTen[30], daoDuc[10], gioiTinh[10];
		int ngay, thang, namSinh;
		float diemTrungBinh;
		
	public:
		void input(){
			cout << "Nhap ho ten: ";
			gets(hoTen);
			cout << "Nhap ngay: ";
			cin >> ngay;
			cout << "Nhap thang: ";
			cin >> thang;
			cout << "Nhap nam: ";
			cin >> namSinh;
			cin.ignore();
			cout << "Nhap gioi tinh: ";
			gets(gioiTinh);
			cout << "Nhap dao duc: ";
			gets(daoDuc);
			cout << "Nhap diem tb: ";
			cin >> diemTrungBinh;
		};
		
		void output(){
			cout << "\n===== THONG TIN HOC SINH =====\n";
	        cout << "Ho ten: " << hoTen << endl;
	        cout << "Ngay sinh: " << ngay << "/" << thang << "/" << namSinh << endl;
	        cout << "Gioi tinh: " << gioiTinh << endl;
	        cout << "Diem trung binh: " << diemTrungBinh << endl;
	        cout << "Xep loai dao duc: " << daoDuc << endl;
		};
};


int main(){
	hocSinh hs;
	hs.input();
	hs.output();
}
