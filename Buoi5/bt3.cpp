#include<bits/stdc++.h>
using namespace std;

class MayIn{
	private:
		char tenMay[30];
		char mauSac[10];
		long gia;
		
	public:
		MayIn(){
			strcpy(tenMay, "Hitachi 10x");
			strcpy(mauSac, "Den");
			gia = 200;
		}
		
		MayIn(char *tenMay, char *mauSac, long gia){
			strcpy(this->tenMay, tenMay);
			strcpy(this->mauSac, mauSac);
			this->gia = gia;
		}
		
		bool operator--(){
			if(strcmp(mauSac, "trang") ==0 && gia > 95){
				return true;
			}
			
			return false;
		}
		
		bool operator==(MayIn &a){
			if(strcmp(tenMay, a.tenMay) == 0 && gia == a.gia){
				return true;
			}
			
			return false;
		}
		
	friend istream& operator>>(istream &in, MayIn &a){
		cout << "Nhap ten may: ";
		fflush(stdin), gets(a.tenMay);
		cout << "Nhap mau sac: ";
		fflush(stdin), gets(a.mauSac);
		cout << "Nhap gia: ";
		in >> a.gia;
		return in;
	}
	
	friend ostream& operator<<(ostream &out, MayIn &a){
		out << "Ten may: " << a.tenMay << endl;
		out << "Mau sac: " << a.mauSac << endl;
		out << "Gia: " << a.gia << endl;
		return out;
	}
	
};

int main(){
	MayIn A, B("canon", "trang", 10);
	
	cout << "Nhap thong tin may A: " << endl;
	cin >> A;
	
	cout << "----- Thong tin may A: " << endl;
	cout << A;
	cout << "----- Thong tin may B: " << endl;
	cout << B;
	cout << "-----------------------------" << endl;
	
	bool checkA = --A;
	bool checkB = --B;
	if(checkA){
		cout << "May in A co mau trang va gia > 95" << endl;
	}
	
	if(checkB){
		cout << "May in B co mau trang va gia > 95" << endl;
	}
	
	if(!(checkA) && !(checkB)){
		cout << "Khong co may nao co mau trang va gia > 95" << endl;
	}
	
	if(A == B){
		cout << "Hai may cung ten va gia" << endl;
	}else{
		cout << "Hai may khong cung ten va gia" << endl;
	}
	return 0;
}
