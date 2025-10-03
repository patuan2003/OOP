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

class Phieu;
class SanPham{
	private:
		char maSP[10];
		char tenSP[30];
		int soLuong;
		long donGia;

	public:
		void nhap(){
			cout <<  "Nhap ma sp: ";
			fflush(stdin); gets(maSP);	
			cout <<  "Nhap ten sp: ";
			fflush(stdin); gets(tenSP);
			cout <<  "Nhap so luong: ";
			cin >> soLuong;
			cout <<  "Nhap don gia: ";
			cin >> donGia;
		}
		
		void xuat(){
			cout << setw(10) << maSP 
				 << setw(30) << tenSP
				 << setw(20) << soLuong
				 << setw(20) << donGia
				 << setw(20) << thanhTien() << endl;
		}
		
		long thanhTien(){
			return soLuong * donGia;
		}
	
	friend void demSoLuongNhoHon80(Phieu &phieu);
	friend void sapXepGiaGiamDan(Phieu &phieu);
};

class Phieu{
	private: 
		char maPhieu[20];
		char maNCC[20];
		char tenNCC[30];
		char diaChi[50];
		char sdt[15];
		Date ngayLap;
		int n;
		SanPham *sp;
	public:
		void nhap();
		
		void xuat();

	friend void demSoLuongNhoHon80(Phieu &phieu){
		int dem = 0;
		for(int i = 0; i < phieu.n; i++){
			if(phieu.sp[i].soLuong < 80){
				dem++;
			}
		}
		
		cout<< dem << " san pham co so luong < 80" << endl;
	};

	friend void sapXepGiaGiamDan(Phieu &phieu){
		for(int i = 0; i < phieu.n - 1; i++){
			for(int j = 0; j < phieu.n - i - 1; j++){
				if(phieu.sp[j].donGia < phieu.sp[j+1].donGia){
					SanPham tmp = phieu.sp[j];
					phieu.sp[j] = phieu.sp[j+1];
					phieu.sp[j+1] = tmp;
				}
			}
		}
		
		phieu.xuat();
	}

	friend void suaTenNCC(Phieu &phieu){
		strcpy(phieu.tenNCC, "Cty TNHH Thanh Do");
		phieu.xuat();
	}
};

void Phieu::nhap(){
	cout << "Nhap ma phieu: ";
	fflush(stdin); gets(maPhieu);
	cout << "Nhap ma ncc: ";
	fflush(stdin); gets(maNCC);
	cout << "Nhap ten ncc: ";
	fflush(stdin); gets(tenNCC);
	cout << "Nhap dia chi: ";
	fflush(stdin); gets(diaChi);
	cout << "Nhap sdt: ";
	fflush(stdin); gets(sdt);
	cout << "Nhap ngay lap: ";
	ngayLap.nhap();
	cout << "Nhap so luong san pham: ";
	cin >> n;
	sp = new SanPham[n];
	for(int i = 0; i < n; i++){
		cout << "------- San pham thu " << i + 1 << endl;
		sp[i].nhap();
	}
}

void Phieu::xuat(){
	cout << "===> Thong tin phieu" << endl;
	cout << "Ma phieu: " << maPhieu << endl;
	cout << "Ma ncc: " << maNCC << endl;
	cout << "Ten ncc: " << tenNCC << endl;
	cout << "Dia chi: " << diaChi << endl;
	cout << "Sdt: " << sdt << endl;
	cout << "Ngay lap: ";
	ngayLap.xuat();
	
	cout << setw(10) << "ma sp" 
		 << setw(30) << "ten sp"
		 << setw(20) << "so luong"
		 << setw(20) << "don gia"
		 << setw(20) << "thanh tien" << endl;
	for(int i = 0; i < n; i++){
		sp[i].xuat();
	}
}


int main(){
	Phieu phieu;
	int chon;
	
	do{
		cout << "========= Menu =========" << endl;
		cout << "1. Nhap phieu" << endl;
		cout << "2. Xuat phieu" << endl;
		cout << "3. San pham co so luong < 80" << endl;
		cout << "4. Sap xep giam gian theo gia" << endl;
		cout << "5. Sua ten cong ty" << endl;
		cout << "Chon menu: ";
		cin >> chon;
		
		switch(chon){
			case 1:
				phieu.nhap();
				break;
			case 2:
				phieu.xuat();				
				break;
			case 3:
				demSoLuongNhoHon80(phieu);
				break;
			case 4:
				sapXepGiaGiamDan(phieu);
				break;
			case 5: 
				suaTenNCC(phieu);
				break;
			case 0:
				cout << "Chuong trinh ket thuc!" << endl;
				break;
			default:
				cout << "Menu khong co!" << endl;
		}
		
	}while(chon!=0);

	return 0;
}
