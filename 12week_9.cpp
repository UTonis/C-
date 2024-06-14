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
		cout << endl << endl << "����:1, �ּ�:2, ����:3, ������:4>>"; cin >> num;
	}
	static void selectT(){
		while (true){
			cout << "07��:1, 12��:2, 17��:3>>"; cin >> time;
			if (time == 1 || 2 || 3){
				break;
			}
			else{
				cout << "1~3�� �Է����ּ���." << endl;
			}
		}
	}
	static void selectSN(){
		while (true){
			cout << "�¼���ȣ>> "; cin >> seatnum;
			if (seatnum > 0 && seatnum < 9){
				break;
			}
			else{
				cout << "1~8�� �������ּ���." << endl;
			}
		}
		cout << "�̸� �Է�>> "; cin >> name;
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
		sc[0].setn("07��");
		sc[1].setn("12��");
		sc[2].setn("17��");
	}
	~AirlineBook(){
		delete[] sc;
	}
	void run(){
		cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ� *****";
		while (true){
			console::menu();
			if (console::getnum() == 1){
				console::selectT(); //static�ɹ� time�� �ð� ����
				sc[console::gettime() - 1].show(); //�ð��� ����� ��� ���
				console::selectSN(); //�ڸ� ��ȣ, �̸� �Է�
				if ("- - -" == sc[console::gettime() - 1].getN(console::getseatnum() - 1)){
					sc[console::gettime() - 1].setN(console::getseatnum() - 1, console::getname()); // �ڸ� ����
				}
				else{
					cout << "�̹� ����� �ڸ��Դϴ�." << endl;
				}
				
			}
			else if (console::getnum() == 2){
				console::selectT(); //static�ɹ� time�� �ð� ����
				sc[console::gettime() - 1].show(); //�ð��� ����� ��� ���
				console::selectSN(); //�ڸ� ��ȣ, �̸� �Է�
				if (console::getname() == sc[console::gettime() - 1].getN(console::getseatnum() - 1)){
					sc[console::gettime() - 1].setN(console::getseatnum() - 1, "- - -");
				}
				else{
					cout << "�����ڸ��� �ùٸ��� �ʽ��ϴ�." << endl;
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