#include<bits/stdc++.h>
using namespace std;

class IdSach{
	protected:
		int maSach;
		char tenSach[30];
		
	public:
		void nhap(){
			cout << "Nhap ma sach: ";
			cin >> maSach;
			cout << "Nhap ten sach: ";
			fflush(stdin); gets(tenSach);
		}
		
		void xuat(){
			cout << "Ma sach: " << maSach << endl;
			cout << "Ten sach: " << tenSach << endl;
		}
};

class SachGK;
class TacGia{
	private:
		char tenTG[30];
		char diaChiTG[30];
	
	friend void nhapTG(TacGia &tg);
	friend void xuatTG(TacGia &tg);
	friend void nxbKD_tgPhamVanAt(SachGK *a, int n);
};

class NXB{
	private:
		char tenNXB[30];
		char diaChiNXB[30];
		
	friend void nhapNXB(NXB &nxb);
	friend void xuatNXB(NXB &nxb);
	friend void nxbKD_tgPhamVanAt(SachGK *a, int n);
};

class SachGK: public IdSach{
	private:
		TacGia x;
		NXB y;
		
	public:
		void nhap(){
			IdSach::nhap();
			nhapTG(x);
			nhapNXB(y);
		}
		
		void xuat(){
			IdSach::xuat();
			xuatTG(x);
			xuatNXB(y);
		}
	
	friend void nxbKD_tgPhamVanAt(SachGK *a, int n){
		cout << "--------------------------------------------------------------" << endl;
		cout << "==========> Thong tin sach NXB KIMDONG, TG Pham Van At" << endl;
		for(int i = 0; i < n; i++){
			cout << "==========> Thong tin sach thu " << i + 1 << endl;
			if((strcmp(a[i].x.tenTG, "Pham Van At") == 0 
				&& strcmp(a[i].y.tenNXB, "KIMDONG") == 0)){
					a[i].xuat();
			}
		}
	}
	
	friend void sapXepGiamDanMaSach(SachGK *s, int n);
};

void nhapTG(TacGia &tg){
	cout << "Nhap ten tg: ";
	fflush(stdin); gets(tg.tenTG);
	cout << "Nhap dia chi tg: ";
	fflush(stdin); gets(tg.diaChiTG);
}

void xuatTG(TacGia &tg){
	cout << "Ten tg: " << tg.tenTG << endl;
	cout << "Dia chi tg: " << tg.diaChiTG << endl;
}

void nhapNXB(NXB &nxb){
	cout << "Nhap ten nxb: ";
	fflush(stdin); gets(nxb.tenNXB);
	cout << "Nhap dia chi nxb: ";
	fflush(stdin); gets(nxb.diaChiNXB);
}

void xuatNXB(NXB &nxb){
	cout << "Ten nxb: " << nxb.tenNXB << endl;
	cout << "Dia chi nxb: " << nxb.diaChiNXB << endl;
}

void swap(SachGK &s1, SachGK &s2){
	SachGK temp = s1;
	s1 = s2;
	s2 = temp;
}

void sapXepGiamDanMaSach(SachGK *s, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(s[j].maSach < s[j + 1].maSach){
				swap(s[j], s[j + 1]);
			}
		}
	}
}

int main(){
	int n;
	SachGK *s;
	
	do{
		cout << "Nhap so luong sach: ";
		cin >> n;
	}while(n <= 0);
	
	s = new SachGK[n];
	for(int i = 0; i < n; i++){
		cout << "==========> Nhap thong tin sach thu " << i + 1 << endl;
		s[i].nhap();
	}

	cout << "------------------------------------------------------" << endl;
	for(int i = 0; i < n; i++){
		cout << "==========> Thong tin sach thu " << i + 1 << endl;
		s[i].xuat();
	}
	
	nxbKD_tgPhamVanAt(s, n);
	sapXepGiamDanMaSach(s, n);
	for(int i = 0; i < n; i++){
		cout << "---------------------------------------------" << endl;
		cout << "THONG TIN SACH SAU SAP XEP" << endl;
		cout << "==========> Thong tin sach thu " << i + 1 << endl;
		s[i].xuat();
	}
	return 0;
}
