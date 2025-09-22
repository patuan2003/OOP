#include<bits/stdc++.h>
using namespace std;

class phuongTrinhBacHai{
	private:
		float a, b, c;
		
	public:
		void nhap();
		void xuat();
};

void phuongTrinhBacHai::nhap(){
	cout << "Nhap he so a: "; 
	cin >> a;
	cout << "Nhap he so b: "; 
	cin >> b;
	cout << "Nhap he so c: "; 
	cin >> c;
}

void phuongTrinhBacHai::xuat(){
	if(a == 0){
		if(b == 0){
			if(c==0){
				cout << "Phuong trinh co vo so nghiem";
			}else{
				cout << "Phuong trinh vo nghiem";
			}
		}else{
			cout<<"Phuong trinh co nghiem la: " << -c/b << endl;  
		}
	}else{
		float delta = b*b - 4*a*c;
		if(delta < 0){
			cout << "Phuong trinh vo nghiem";
		}else if(delta == 0){
			cout << "Phuong trinh co nghiem kep: " << -b/(2*a) << endl;
		}else{
			float x1 = (-b + sqrt(delta))/(2*a);
			float x2 = (-b - sqrt(delta))/(2*a);
			cout << "Phuong trinh co 2 nghiem phan biet: " << endl;
			cout << "x1= " << x1 << endl;
			cout << "x2= " << x2;
		}
	}
}


int main(){
	phuongTrinhBacHai pt;
	pt.nhap();
	pt.xuat();
}
