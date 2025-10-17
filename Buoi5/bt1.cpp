#include<bits/stdc++.h>
using namespace std;

class PhanSo{
	private:
		int TS, MS;
		
	public:
		PhanSo(){
			TS = 0;
			MS = 1;
		};
		
		PhanSo(int TS, int MS){
			this->TS = TS;
			this->MS = MS;
		}
	
	PhanSo operator+(PhanSo& p){
		PhanSo kq;
		kq.TS = TS * p.MS + p.TS*MS;
		kq.MS = p.MS * MS;
		return kq;
	}
	
	PhanSo operator-(PhanSo& p){
		PhanSo kq;
		kq.TS = TS * p.MS - p.TS * MS;
		kq.MS = MS * p.MS;
		return kq;
	}
	
	PhanSo operator-(){
		PhanSo kq;
		kq.TS = -TS;
		kq.MS = MS;
		return kq;
	}
	
	float operator--(){
		return (float) TS/MS;
	}
	
	friend istream& operator>>(istream& in, PhanSo& p){
		cout << "Nhap tu so: ";
		in >> p.TS;
		cout << "Nhap mau so: ";
		in >> p.MS;
		
		return in;
	};
	
	friend ostream& operator<<(ostream& out, PhanSo p){
		out << p.TS << "/" << p.MS;
		return out;
	};
};

int main(){
	PhanSo P(3, 5), Q;
	cout << "Nhap phan so Q: " << endl;
	cin >> Q;
	
	PhanSo tong = P + Q;
	PhanSo hieu = P - Q;
	
	cout << "Phan so P = " << P << endl;
    cout << "Phan so Q = " << Q << endl;
    cout << "Tong = " << tong << " = " << --tong << endl;
    cout << "Hieu = " << hieu << " = " << --hieu << endl;
    cout << "Hieu doi dau = " << -hieu << endl;
	return 0;
}
