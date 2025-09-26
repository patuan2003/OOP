#include<bits/stdc++.h>
using namespace std;

class HangHoa{
	private:
		int maHang;
		char tenHang[50];
		long tienTra;
	

	friend class PhieuMuaHang;
};

class PhieuMuaHang{
	private:
		int maPhieu;
		char tenKhach[30];
		int n;
		HangHoa *a;
		
	public:
		void nhap();
		
		void xuat();
};

void PhieuMuaHang::nhap(){
	cout << "Nhap ma phieu: ";
	cin >> maPhieu;
	cout << "Nhap ten khach: ";
	fflush(stdin); gets(tenKhach);
	
	do{
		cout << "Nhap so luong hang hoa: ";
		cin >> n;
	}while(n <= 0);
	
	a = new HangHoa[n];
	
	for(int i = 0; i < n; i++){
			cout << "Nhap hang hoa thu " << i + 1 << endl;
			cout << "Nhap ma hang hoa: ";
			cin >> a[i].maHang;
			cout << "Nhap ten hang: ";
			fflush(stdin); gets(a[i].tenHang);
			cout << "Nhap tien tra: ";
			cin >> a[i].tienTra;
		}
}

void PhieuMuaHang::xuat(){
	cout << "<<<<<<<<< Thong tin phieu mua hang >>>>>>>>>" << endl;
	cout << "Ma phieu: " << maPhieu << endl;
	cout << "Ten khach: " << tenKhach << endl;
	
	cout << "Thong tin hang hoa: " << endl;
	
	int totalPrice = 0;
	cout << setw(10) << "Ma phieu" << setw(20) << "Ten hang" << setw(20) << "Tien tra" << endl; 
	for(int i = 0; i < n; i++){
		cout << setw(10) << a[i].maHang << setw(20) << a[i].tenHang << setw(20) << a[i].tienTra << endl; 
		
		totalPrice += a[i].tienTra;
	}
	
	cout << setw(60) << "Tong tien hang: " << totalPrice << endl;
}

int main(){
	PhieuMuaHang pmh;
	pmh.nhap();
	pmh.xuat();
	return 0;
}
