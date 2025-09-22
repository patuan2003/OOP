#include<bits/stdc++.h>
using namespace std;

class PhuongTrinhBacNhat{
	private:
		float a,b;
	
	public:
		void nhap();
		
		void xuat();
};


void PhuongTrinhBacNhat::nhap(){
	cout<<"Nhap he so a: ";
	cin>>a;
	cout<<"Nhap he so b: ";
	cin>>b;
}
	
void PhuongTrinhBacNhat::xuat(){
	if(a == 0){
		if(b == 0){
			cout<< "Phuong trinh vo so ngiem";
		}else{
			cout<< "Phuong trinh vo nghiem";
		}
	}else{
		cout<<"Ket qua: " << -b/a << endl;
	}
}
	
int main(){
	PhuongTrinhBacNhat pt;
		pt.nhap();
		pt.xuat();

	
}
