#include<bits/stdc++.h>
using namespace std;

class HocSinh{
	private:
		char hoTen[30];
		int tuoi;
		float diemToan, diemLy, diemHoa;
		
	public:
		HocSinh(){
			strcpy(hoTen, "Nguyen Van A");
			tuoi = 18;
			diemToan = 6.5;
			diemLy = 7;
			diemHoa = 8.1;
		}
		
		HocSinh(char *hoTen, int tuoi, float diemToan, float diemLy, float diemHoa){
			strcpy(this->hoTen, hoTen);
			this->tuoi = tuoi;
			this->diemToan = diemToan;
			this->diemLy = diemLy;
			this->diemHoa = diemHoa;
		}
		
		void xuat(){
			cout << "Ho ten: " << hoTen << endl;
			cout << "Tuoi: " << tuoi << endl;
			cout << "Diem toan: " << diemToan << endl;
			cout << "Diem ly: " << diemLy << endl;
			cout << "Diem hoa: " << diemHoa << endl;
			
		}
};

int main(){
	HocSinh hs1;
	cout << "=====> Hoc sinh thu 1: " << endl;
	hs1.xuat();
	
	HocSinh hs2("Tao thao", 20, 5.5, 6, 7);
	cout << "=====> Hoc sinh thu 2: " << endl;
	hs2.xuat();
}
