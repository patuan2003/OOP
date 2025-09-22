#include<bits/stdc++.h>
using namespace std;

class hinhTamGiac{
	private: 
		float a, b, c;

	public:
		void nhap(){
			cout << "Nhap canh a: ";
			cin >> a;
			cout << "Nhap canh b: ";
			cin >> b;
			cout << "Nhap canh c: ";
			cin >> c;
		};
		
		float chuVi(){
			return a + b + c;
		};
		
		float dienTich(){
			float p = chuVi()/2;
			return sqrt(p * (p - a) * (p - b) * (p - c));
		};
		
		void xuat(){
			if(a + b <= c || b + c <= a || c + a <= b){
				cout << "3 canh khong tao thanh 1 tam giac hop le" << endl;
				return;
			}
			cout << "Chu vi hinh tam giac: " << chuVi() << endl;
			cout << "Dien tich hinh tam giac: " << dienTich() << endl;
		};
};


int main(){
	hinhTamGiac htg;
	htg.nhap();
	htg.xuat();
}
