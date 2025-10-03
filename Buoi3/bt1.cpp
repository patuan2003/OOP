#include<bits/stdc++.h>
using namespace std;

class DoanhNghiep;
class Date{
	private:
		int d, m, y;
	
	public:
		void nhap(){
			cout << "Nhap ngay, thang, nam: ";
			cin >> d >> m >> y;
		};
		
		void xuat(){
			cout << d << "/" << m << "/" << y; 
		};
		
	friend void doanhThu2015(DoanhNghiep *dn, int n);
};


class DiaChi{
	private:
		char sdt[12];
		char phuong[30];
		char quan[30];
		char thanhPho[30];
		
	friend void nhapDC(DoanhNghiep &dn);
	friend void xuatDC(DoanhNghiep &dn);
	friend void diaChiHaNoi(DoanhNghiep *dn, int n);
	
};

class DoanhNghiep{
	private:
		int maDn;
		char tenDn[30];
		Date ngayTl;
		DiaChi diaChi;
		char giamDoc[30];
		long doanhThu;
	
	public:
		void nhap();
		void xuat();
		
	friend void diaChiHaNoi(DoanhNghiep *dn, int n);
	friend void nhapDC(DoanhNghiep &dn);
	friend void xuatDC(DoanhNghiep &dn);
	friend void doanhThu2015(DoanhNghiep *dn, int n);
	friend void suaDoanhNghiep(DoanhNghiep *dn, int n);

};

void DoanhNghiep::nhap(){
	cout << "Nhap ma DN: ";
	cin >> maDn;
	cout << "Nhap ten DN: ";
	fflush(stdin); gets(tenDn);
	cout << "Nhap ngay thanh lap: " << endl;
	ngayTl.nhap();
	nhapDC(*this);
	cout << "Nhap giam doc: ";
	fflush(stdin); gets(giamDoc);
	cout << "Nhap doanh thu: ";
	cin >> doanhThu;
}

void DoanhNghiep::xuat(){
			cout << "Ma DN: " << maDn << endl;
	        cout << "Ten DN: " << tenDn << endl;
	        cout << "Ngay TL: "; ngayTl.xuat(); cout << endl;
			xuatDC(*this);
	        cout << "Giam doc: " << giamDoc << endl;
	        cout << "Doanh thu: " << doanhThu << endl;
};

void nhapDC(DoanhNghiep &dn){
		cout << "Nhap sdt: ";
		fflush(stdin); gets(dn.diaChi.sdt);
		cout << "Nhap phuong: ";
		fflush(stdin); gets(dn.diaChi.phuong);
		cout << "Nhap quan: ";
		fflush(stdin); gets(dn.diaChi.quan);
		cout << "Nhap thanh pho: ";
		fflush(stdin); gets(dn.diaChi.thanhPho);
};

void xuatDC(DoanhNghiep &dn){
	    cout << "Dien thoai: " << dn.diaChi.sdt << endl;
        cout << "Phuong: " << dn.diaChi.phuong << endl;
        cout << "Quan: " << dn.diaChi.quan << endl;
        cout << "Thanh pho: " << dn.diaChi.thanhPho << endl;
};

void diaChiHaNoi(DoanhNghiep *dn, int n){
	cout << "=====> Doanh nghiep o Ha Noi: " << endl;
	for(int i = 0; i < n; i++){
		if(strcmp(dn[i].diaChi.thanhPho, "Ha Noi") == 0){
			dn[i].xuat();
		}
	}
}

void doanhThu2015(DoanhNghiep *dn, int n){
	long tong = 0;
	for(int i = 0; i < n; i++){
		if(dn[i].ngayTl.y == 2015){
			tong += dn[i].doanhThu;
		}
	}
	
	cout << "Tong doanh thu cua nhung doanh nghiep 2015 la: " << tong << endl;
}

void suaDoanhNghiep(DoanhNghiep *dn, int n){
	int ma;
	bool isCheck = false;
	cout << "Nhap ma DN can sua: ";
	cin >> ma;
	for(int i = 0; i < n; i++){
		if(ma == dn[i].maDn){
			isCheck = true;
			dn[i].nhap();
			break;
		}
	}
	
	if(!isCheck){
		cout << "Ma DN khong ton tai!" << endl;
	}
}

int main(){
	int chon;
	int n;
	DoanhNghiep *dn;
	
	do{
		cout << "========== MENU ==========" << endl;
		cout << "1. Nhap danh sach doanh nghiep" << endl;
		cout << "2. Xuat danh sach doanh nghiep" << endl;
		cout << "3. Hien thi danh sach doanh nghiep o Ha Noi" << endl;
		cout << "4. Tinh tong doanh thu doanh nghiep 2015" << endl;
		cout << "5. Nhap ma DN de sua thong tin" << endl;
		cout << "0. Ket thuc chuong trinh" << endl;
		cout << "Chon menu: ";
		cin >> chon;
		
		switch(chon){
			case 1:  
				do{
					cout << "Nhap so luong doanh nghiep: ";
					cin >> n;	
				}while(n <= 0 || n > 20);
				
				dn = new DoanhNghiep[n];
				
				for(int i = 0; i < n; i++){
					cout << ">>>>>>>>>> Nhap thong tin doanh nhiep thu " << i + 1 << endl;
					dn[i].nhap();
				}
				
				break;
			case 2: 
				for(int i = 0; i < n; i++){
					cout << ">>>>>>>>>> Thong tin doanh nghiep thu " << i + 1 << endl;
					dn[i].xuat();
				}
				
				break;
			case 3:
				diaChiHaNoi(dn, n);
				break;
			case 4:
				doanhThu2015(dn, n);
				break;
			case 5: 
				suaDoanhNghiep(dn, n);
				break;
			case 0: 
				cout << "Chuong trinh da ket thuc!" << endl;
				break;
			default: 
				cout << "Chuc nang khong hop le!" << endl;
		} 
	
	}while(chon != 0);
	
	return 0;
}
