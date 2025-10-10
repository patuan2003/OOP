#include<bits/stdc++.h>
using namespace std;

class Student;
class School{
	private:
		char name[30];
		char date[15];
		
	friend void inputSchool(School &s);
	friend void outputSchool(School &s);
	friend void editNameSchool(Student &s);
};

void inputSchool(School &s){
	cout << "Enter name school: ";
	fflush(stdin); gets(s.name);
	cout << "Enter date school: ";
	fflush(stdin); gets(s.date);
}

void outputSchool(School &s){
	cout << "Name school: " << s.name << endl;
	cout << "Date school: " << s.date << endl;
}

class Faculty{
	private:
		char name[30];
		char date[20];
		School x;
	
	public:
		void input(){
			inputSchool(x);
			cout << "Enter name faculty: ";
			fflush(stdin); gets(name);
			cout << "Enter date faculty: ";
			fflush(stdin); gets(date);
		};
		
		void output(){
			outputSchool(x);
			cout << "Name faculty: " << name << endl;
			cout << "Date faculty: " << date << endl;
		};
	
	
	friend void editNameSchool(Student &s);
};

class Person{
	protected:
		char name[30];
		char birth[20];
		char address[30];
	
	public:
		Person(){};
		
		void inputPerson(){
			cout << "Enter name person: ";
			fflush(stdin); gets(name);
			cout << "Enter birth: ";
			fflush(stdin); gets(birth);
			cout << "Enter address: ";
			fflush(stdin); gets(address);
		};
		
		void outputPerson(){
			cout << "Name person: " << name << endl;
			cout << "Birth: " << birth << endl;
			cout << "Address: " << address << endl;
		};
		
};

class Student: public Person{
	private:
		Faculty y;
		char className[20];
		float score;
		
	public:
		Student(){};
		
		void inputStudent() {
	        Person::inputPerson();
	        y.input();
	        cout << "Enter class name: ";
	        fflush(stdin); gets(className);
	        cout << "Enter score: ";
	        cin >> score;
	    }
	
	    void outputStudent() {
	        Person::outputPerson();
	        y.output();
	        cout << "Class name: " << className << endl;
	        cout << "Score: " << score << endl;
	    }
	
	friend void editNameSchool(Student &s);
};

void editNameSchool(Student &s){
	strcpy(s.y.x.name, "DHCNHN");
}

int main(){
	Student st;
	st.inputStudent();
	
	cout << "---------- Output Student ----------" << endl;
	st.outputStudent();
	
	cout << "---------- Edit Student ----------" << endl;
	editNameSchool(st);
	st.outputStudent();
	return 0;
}
