#include<bits/stdc++.h>
using namespace std;

class HinhThang{
	private:
		float a, b, h;
	
	public:
		void input(){
			cout<<"Nhap day lon: ";
			cin>>a;
			cout<<"Nhap day nho: ";
			cin>>b;
			cout<<"Nhap chieu cao: ";
			cin>>h;
		};
		
		void output();
		
		float dienTich();
	
};

float HinhThang::dienTich(){
	return (a + b) * h/2;
}

void HinhThang::output(){
	cout<<"Day lon la: " << a << endl;
	cout<<"Day nho la: " << b << endl;
	cout<<"Chieu cao la: " << h << endl;
	cout<<"Dien tich la: " << dienTich() << endl;
}

int main(){
	HinhThang ht;
	ht.input();
	ht.output();
};
