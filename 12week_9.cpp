#include <iostream>
#include <string>
using namespace std;

class console{
	static int num;
	static int time;
	static int seatnum;
	static string name;
public:
	static int gettime(){
		return time;
	}
	static int getseatnum(){
		return seatnum;
	}
	static int getnum(){
		return num;
	}
	static string getname(){
		return name;
	}
	static void menu(){
		cout << endl << endl << "에약:1, 최소:2, 보기:3, 끝내기:4>>"; cin >> num;
	}
	static void selectT(){
		while (true){
			cout << "07시:1, 12시:2, 17시:3>>"; cin >> time;
			if (time == 1 || 2 || 3){
				break;
			}
			else{
				cout << "1~3을 입력해주세요." << endl;
			}
		}
	}
	static void selectSN(){
		while (true){
			cout << "좌석번호>> "; cin >> seatnum;
			if (seatnum > 0 && seatnum < 9){
				break;
			}
			else{
				cout << "1~8을 선택해주세요." << endl;
			}
		}
		cout << "이름 입력>> "; cin >> name;
	}
};

int console::num;
int console::time;
int console::seatnum;
string console::name;

class seat{
	string name;
public:
	seat(){
		this->name = "- - -";
	}
	string getN(){
		return name;
	}
	void setN(string name){
		this->name = name;
	}
	void show(){
		cout << this->name;
	}
};

class Schedule{
	seat *s;
	string n;
public:
	Schedule(){
		s = new seat[8];
	}
	~Schedule(){
		delete[] s;
	}
	void setn(string n){
		this->n = n;
	}
	string getN(int sn){
		return s[sn].getN();
	}
	void setN(int sn, string name){
		s[sn].setN(name);
	}
	void show(){
		cout << n;
		for (int i = 0; i < 8; i++){
			cout << "     "; s[i].show();
		}
		cout << endl;
	}
};
class AirlineBook{
	Schedule *sc;
public:
	AirlineBook(){
		sc = new Schedule[3];
		sc[0].setn("07시");
		sc[1].setn("12시");
		sc[2].setn("17시");
	}
	~AirlineBook(){
		delete[] sc;
	}
	void run(){
		cout << "***** 한성항공에 오신것을 환영합니다 *****";
		while (true){
			console::menu();
			if (console::getnum() == 1){
				console::selectT(); //static맴버 time에 시간 저장
				sc[console::gettime() - 1].show(); //시간에 예약된 명단 출력
				console::selectSN(); //자리 번호, 이름 입력
				if ("- - -" == sc[console::gettime() - 1].getN(console::getseatnum() - 1)){
					sc[console::gettime() - 1].setN(console::getseatnum() - 1, console::getname()); // 자리 예약
				}
				else{
					cout << "이미 예약된 자리입니다." << endl;
				}
				
			}
			else if (console::getnum() == 2){
				console::selectT(); //static맴버 time에 시간 저장
				sc[console::gettime() - 1].show(); //시간에 예약된 명단 출력
				console::selectSN(); //자리 번호, 이름 입력
				if (console::getname() == sc[console::gettime() - 1].getN(console::getseatnum() - 1)){
					sc[console::gettime() - 1].setN(console::getseatnum() - 1, "- - -");
				}
				else{
					cout << "예약자명이 올바르지 않습니다." << endl;
				}
			}
			else if (console::getnum() == 3){
				for (int i = 0; i < 3; i++){
					sc[i].show();
				}
			}
			else if (console::getnum() == 4){
				break;
			}
		}
	}
};

int main(){
	AirlineBook ab;
	ab.run();
}