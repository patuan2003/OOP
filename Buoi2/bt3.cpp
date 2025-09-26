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

class HangHoa{
	private:
		char maHang[10];
		char tenHang[20];
		long donGia;
		int soLuong;
	
	public:
		void nhap(){
			cout << "Nhap ma hang: " ;
			fflush(stdin); gets(maHang);
			cout << "Nhap ten hang: ";
			fflush(stdin); gets(tenHang);
			cout << "Nhap don gia: ";
			cin >> donGia;
			cout << "Nhap so luong: ";
			cin >> soLuong;
		}
		
		void xuat(){
			cout << setw(10) << maHang << setw(20) << tenHang << setw(10) << donGia 
			<< setw(10) << soLuong << setw(20) << thanhTien() << endl;
		}
		
		long thanhTien(){
			return donGia * soLuong;
		}
		
		int getSoLuong(){
			return soLuong;
		}
		
};

class PhieuMuaHang{
	private:
		char maPhieu[10];
		char maNguoiLapPhieu[10];
		char tenNguoiLapPhieu[30];
		char tenKH[30];
		Date ngayLapPhieu;
		int n;
		HangHoa *a;
		
	public:
		void nhap(){
			cout << "Nhap ma phieu: ";
			fflush(stdin); gets(maPhieu);
			cout << "Nhap ma nguoi lap phieu: ";
			fflush(stdin); gets(maNguoiLapPhieu);
			cout << "Nhap ten nguoi lap phieu: ";
			fflush(stdin); gets(tenNguoiLapPhieu);
			cout << "Nhap ten KH: ";
			fflush(stdin); gets(tenKH);
			cout << "Nhap ngay lap phieu: ";
			ngayLapPhieu.nhap();
			
			do{
				cout << "Nhap so luong hang hoa: ";
				cin >> n;
			}while(n <= 0);
			
			a = new HangHoa[n];
			for(int i = 0; i < n; i++){
				cout << "====> Nhap hang hoa " << i + 1 << endl;
				a[i].nhap();
			}
		}
	
		void xuat(){
			cout << ">>>>>>>>> Thong tin phieu mua hang <<<<<<<<<" << endl;
			cout << "Ma phieu: " << maPhieu << endl;
			cout << "Ma nguoi lap phieu: " << maNguoiLapPhieu << endl;
			cout << "Ten nguoi lap phieu: " << tenNguoiLapPhieu << endl;
			cout << "Ten KH: " << tenKH << endl;
			cout << "Ngay lap phieu: ";
			ngayLapPhieu.xuat();
			
			long totalPrice =0;
			int totalQuantity = 0;
			cout << "-----> Thong tin hang hoa" << endl;
			cout << setw(10) << "Ma hang" << setw(20) << "Ten hang" << setw(10) 
				<< "Don gia" << setw(10) << "So luong" << setw(20) << "Thanh tien" << endl;
			for(int i = 0; i < n; i++){
				a[i].xuat();``
				totalPrice += a[i].thanhTien();
				totalQuantity += a[i].getSoLuong() ;
			}
			
			cout << setw(10) << "Tong: " << setw(40) << totalQuantity << setw(20) << totalPrice << endl; 
 		}
 		
 		void maxSL(){
			int maxSl = 0;
			for(int i = 0; i < n; i++){
				maxSl = max(maxSl, a[i].getSoLuong());
			}
			
			
			cout << ">>>>>>>Don hang co so luong nhieu nhat: " << endl;
			for(int i = 0; i < n; i++){
				if(a[i].getSoLuong() == maxSl){
					a[i].xuat();
				}
			}
		}

};

int main(){
	PhieuMuaHang pmh;
	pmh.nhap();
	pmh.xuat();
	pmh.maxSL();
	return 0;
}
