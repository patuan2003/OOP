#include<bits/stdc++.h>
using namespace std;

class hinhTron{
	private:
		float BK;
	
	public:
		void nhap(){
			cout << "Nhap ban kinh: ";
			cin >> BK;
		};
		
		void xuat(){
			cout << "chu vi hinh tron: " << chuVi() << endl;
			cout << "Dien tich hinh tron: " << dienTich() << endl; 
		};
		
		float chuVi(){
			return 2 * M_PI * BK;
		};
		
		float dienTich(){
			return M_PI * BK * BK;
		};
};

int main(){
	hinhTron ht;
	ht.nhap();
	ht.xuat();
};
