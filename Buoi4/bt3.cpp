#include<bits/stdc++.h>
using namespace std;

class Hang{
	protected:
		int maHang;
		char tenHang[30];
		long gia;
		
	public:
		void nhap(){
			cout << "Nhap ma hang: ";
			cin >> maHang;
			cout << "Nhap ten hang: ";
			fflush(stdin); gets(tenHang);
			cout << "Nhap gia: ";
			cin >> gia;
		};
		void xuat(){
			cout << "Ma hang: " << maHang << endl;
			cout << "Ten hang: " << tenHang << endl;
			cout << "Gia: " << gia << endl;
		};
};

class CuaHang;
class HangMM: public Hang{
	private:
		char chatLieu[20];
		char kieuDang[20];
		int soLuong;
	public:
		void nhap(){
			Hang::nhap();
			cout << "Nhap chat lieu: ";
			fflush(stdin); gets(chatLieu);
			cout << "Nhap kieu dang: ";
			fflush(stdin); gets(kieuDang);
			cout << "Nhap so luong: ";
			cin >> soLuong;
		};
		void xuat(){
			Hang::xuat();
			cout << "Chat lieu: " << chatLieu << endl;
			cout << "Kieu dang: " << kieuDang << endl;
			cout << "So luong: " << soLuong << endl;
		};
		
	friend void hienThiSoLuongLonHon25(CuaHang &ch);
};

class CuaHang{
	private:
		int maCH;
		char tenCH[20];
		HangMM *x;
		int n;
	
	public:
		void nhap(){
			cout << "Nhap ma CH: ";
			cin >> maCH;
			cout << "Nhap ten CH: ";
			fflush(stdin); gets(tenCH);
			cout << "Nhap so luong hang mm: ";
			cin >> n;
			
			x = new HangMM[n];
			for(int i = 0; i < n; i++){
		   		cout << "==========> Nhap thong tin hang may mac thu " << i + 1 << endl;
				x[i].nhap();
			}
		};
		
		void xuat(){
			cout << "Ma CH: " << maCH << endl;
			cout << "Ten CH: " << tenCH << endl;
			for(int i = 0; i < n; i++){
				x[i].xuat();
			}
		};
		
	friend void suaTenCH(CuaHang &ch);
	friend void hienThiSoLuongLonHon25(CuaHang &ch);
};

void suaTenCH(CuaHang &ch){
	if(strcmp(ch.tenCH, "IVYMODA") == 0){
		cout << "Ten cua hang da la IVYMODA" << endl;
	}else{
		strcpy(ch.tenCH, "IVYMODA");
		cout << "Doi ten thanh cong" << endl;
	}
}

void hienThiSoLuongLonHon25(CuaHang &ch){
	cout << "----------------------------------------------------" << endl;
	cout << "=========> HangMM co so luong > 25" << endl;
	for(int i = 0; i < ch.n; i++){
		if(ch.x[i].soLuong > 25){
			ch.x[i].xuat();
		}
	}
}

int main(){
	CuaHang ch;
	ch.nhap();
	cout << "----------------------------------------------------" << endl;
	ch.xuat();
	
	cout << "----------------------------------------------------" << endl;
	suaTenCH(ch);
	ch.xuat();
	
	cout << "----------------------------------------------------" << endl;
	hienThiSoLuongLonHon25(ch);
	return 0;
}
