#include<bits/stdc++.h>
using namespace std;

class SoPhuc{
	private:
		float phanThuc;
		float phanAo;
	
	public:
		SoPhuc operator+(SoPhuc &sp){
			SoPhuc kq;
			kq.phanThuc = phanThuc + sp.phanThuc;
			kq.phanAo = phanAo + sp.phanAo;
			return kq;
		}
		
		bool operator=(SoPhuc &sp){
			if(phanThuc > 0 && sp.phanThuc >0 && phanThuc == sp.phanThuc 
				&& phanAo > 0 && sp.phanAo > 0 && phanAo == sp.phanAo){
				return true;
			}
			
			return false;
		}
		
	friend istream& operator>>(istream &in, SoPhuc &sp){
		cout << "Nhap phan thuc: ";
		in >> sp.phanThuc;
		cout << "Nhap phan ao: ";
		in >> sp.phanAo;
		return in;
	}
	
	friend ostream& operator<<(ostream &out, SoPhuc &sp){
		out << sp.phanThuc << " + " << sp.phanAo << "i" << endl;
		return out;
	}
};

int main(){
	SoPhuc A, B;
	cout << "Nhap so phuc A: " << endl;
	cin >> A;
	cout << "Nhap so phuc B: " << endl;
	cin >> B;
	cout << "Thong tin so phuc A: " << endl;
	cout << A;
	cout << "Thong tin so phuc B: " << endl;
	cout << B;
	
	SoPhuc C = A + B;
	cout << "Tong cua 2 so phuc: " << C << endl;
	cout << "A va B " << ((A = B) ? "co" : "khong") <<" bang nhau!";
	return 0;
}
