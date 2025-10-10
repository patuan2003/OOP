#include<bits/stdc++.h>
using namespace std;

class SanPham{
	protected:
		int maSP;
		char tenSP[30];
		char ngaySX[20];
		float trongLuong;
		char mauSac[20];
	
	public:
		void nhap(){
			cout << "Nhap ma sp: ";
			cin >> maSP;
			cout << "Nhap ten sp: ";
			fflush(stdin); gets(tenSP);
			cout << "Nhap ngay san xuat: ";
			fflush(stdin); gets(ngaySX);
			cout << "Nhap trong luong: ";
			cin >> trongLuong;
			cout << "Nhap mau sac: ";
			fflush(stdin); gets(mauSac);
		};
		
		void xuat(){
			cout << "Ma sp: " << maSP << endl;
			cout << "Ten sp: " << tenSP << endl;
			cout << "Ngay SX: " << ngaySX << endl;
			cout << "Trong luong: " << trongLuong << endl;
			cout << "Mau sac: " << mauSac << endl;
		};
};

class HDT: public SanPham{
	private: 
		float congSuat;
		int dongDienSuDung;
	
	public:
		void nhap(){
			SanPham::nhap();
			cout << "Nhap cong suat: ";
			cin >> congSuat;
			cout << "Nhap dong dien su dung: ";
			cin >> dongDienSuDung;
		};
		
		void xuat(){
			SanPham::xuat();
			cout << "Cong suat: " << congSuat << endl;
			cout << "Dong dien su dung: " << dongDienSuDung << " chieu" << endl;
		};
		
	friend void sanPhamTLthapNhat(HDT *hdt, int n);
};

	void sanPhamTLthapNhat(HDT *hdt, int n){
		float minTL = hdt[0].trongLuong;
		for(int i = 1; i < n; i++){
			if(minTL > hdt[i].trongLuong){
				minTL = hdt[i].trongLuong;
			}
		}
		
		for(int i = 0; i < n; i++){
			if(minTL == hdt[i].trongLuong){
				cout << "=========> Thong tin san pham co trong luong thap nhat " << i + 1 << endl;
				hdt[i].xuat();
			}
		}
	}

int main(){
	int n;
	HDT *hdt;
	
	do{
		cout << "Nhap so luong hang: ";
		cin >> n;
	}while( n <= 0);
	 
	hdt = new HDT[n];
	 
	for(int i = 0; i < n; i++){
		cout << "==========> Nhap thong tin san pham thu " << i + 1 << endl;
		hdt[i].nhap();
	}
	
	for(int i = 0; i < n; i++){
		cout << "=========> Thong tin san pham thu " << i + 1 << endl;
		hdt[i].xuat();
	}
	
	sanPhamTLthapNhat(hdt, n);
	
	return 0;
}
