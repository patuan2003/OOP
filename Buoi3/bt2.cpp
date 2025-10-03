#include<bits/stdc++.h>
using namespace std;

class Date{
	private:
		int d, m, y;

	public:
		void nhap(){
			cout << "Nhap ngay, thang, nam: ";
			cin >> d >> m >> y;
		};
		
		void xuat(){
			cout << d << "/" << m << "/" << y << endl;
		};
};

class XeHoi{
	private:
		char nhanHieu[10];
		char hangSX[20];
		char kieuDang[20];
		char mauSon[20];
		Date namSX;
		char xuatXu[20];
		long giaBan;
	
	public:
		void nhap(){
			cout << "Nhap nhan hieu: ";
			fflush(stdin); gets(nhanHieu);
			cout << "Nhap hang san xuat: ";
			fflush(stdin); gets(hangSX);
			cout << "Nhap kieu dang: ";
			fflush(stdin); gets(kieuDang);
			cout << "Nhap mau son: ";
			fflush(stdin); gets(mauSon);
			cout << "Nhap nam san xuat: ";
			namSX.nhap();
			cout << "Nhap xuat xu: ";
			fflush(stdin); gets(xuatXu);
			cout << "Nhap gia ban: ";
			cin >> giaBan;
		};
		
		void xuat(){
			cout << "nhan hieu: " << nhanHieu << endl;
			cout << "hang san xuat: " << hangSX << endl;
			cout << "Nhap kieu dang: " << kieuDang << endl;
			cout << "Nhap mau son: " << mauSon << endl;
			cout << "Nhap nam san xuat: ";
			namSX.xuat();
			cout << "xuat xu: " << xuatXu << endl;
			cout << "gia ban: " << giaBan << endl;
		};
	 
	 	 
	friend void xeToyota(XeHoi *xh, int n);
	friend void sapXepGiaTangDan(XeHoi *xh, int n);
};

void xeToyota(XeHoi *xh, int n){
	cout << "=======> Thong tin xe hoi thu Toyota" << endl;
	for(int i = 0; i < n; i++){
		if(strcmp("Toyota", xh[i].hangSX) == 0){
			cout << "=======> Thong tin xe hoi thu " << i + 1 << endl;
			xh[i].xuat();
		}
	}
}

void sapXepGiaTangDan(XeHoi *xh, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(xh[j].giaBan > xh[j + 1].giaBan){
				XeHoi tmp = xh[j];
				xh[j] = xh[j + 1];
				xh[j + 1] = tmp;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << "=======> Thong tin xe hoi thu " << i + 1 << endl;
		xh[i].xuat();
	}
}

int main(){
	int n;
	XeHoi *xh;
	int chon;
    
    do{
    	cout << "========== MENU ==========" << endl;
		cout << "1. Nhap danh sach xe hoi" << endl;
		cout << "2. Xuat danh sach xe hoi" << endl;
		cout << "3. Danh sach xe hoi Toyota" << endl;
		cout << "4. Danh sach theo chieu tang dan gia ban" << endl;
		cout << "0. Ket thuc chuong trinh" << endl;
	    cout << "Chon menu: ";
	    cin >> chon;
    	switch(chon){
			case 1:
				do{
					cout << "Nhap so luong xe hoi: ";
					cin >> n;
				}while(n <= 0);
				
				xh = new XeHoi[n];
				for(int i = 0; i < n; i++){
					cout << "=======> Nhap xe hoi thu " << i + 1 << endl;
					xh[i].nhap();
				}
				break;
			case 2:
				for(int i = 0; i < n; i++){
					cout << "=======> Thong tin xe hoi thu " << i + 1 << endl;
					xh[i].xuat();
				}
				break;
			case 3:
				xeToyota(xh, n);
				break;
			case 4:
				sapXepGiaTangDan(xh, n);
				break;
			case 0: 
				cout << "Chuong trinh da ket thuc!" << endl;
				break;
			default:
				cout << "Xin moi chon lai menu" << endl;
		}
	}while(chon != 0);
	
	return 0;
}


