#include <iostream>
#include <string>
using namespace std;
class Printer {
	string model; //모델명
	string manufacturer; // 제조사
	int printedCount; // 인쇄 매수
	int availableCount; // 인쇄 종이 잔량
public:
	Printer(string model = "", string manufacturer = "", int availableCount = 0, int printedCount = 0) {
		this->model = model;
		this->manufacturer = manufacturer;
		this->printedCount = printedCount;
		this->availableCount = availableCount;
	}
	void print(int pages) {
		if (pages <= availableCount) {
			availableCount -= pages;
			printedCount += pages;
		}
		else {
			cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
		}
	}
	void print();
	virtual void show() = 0;
	string getmodel() {
		return model;
	}
	string getmanufacturer() {
		return manufacturer;
	}
	int getprintedCount() {
		return printedCount;
	}
	int getavailableCount() {
		return availableCount;
	}
};
class InkJetPrinter :public Printer {
	int availableInk; //잉크 잔량
public:
	InkJetPrinter(string model = "", string manufacturer = "", int availableCount = 0, int availableInk = 0) : Printer(model, manufacturer, availableCount){
		this->availableInk = availableInk;
	}
	void show() {
		cout << "잉크젯 : " << getmodel() << ", " << getmanufacturer() << ", 남은 종이 " << getavailableCount() << "장, 남은 잉크" << availableInk << endl;
	}
	int getInk() {
		return availableInk;
	}
};
class laserPrinter :public Printer {
	int availableToner; // 토너 잔량
public:
	laserPrinter(string model = "", string manufacturer = "", int availableCount = 0, int availableToner = 0) : Printer(model, manufacturer, availableCount){
		this->availableToner = availableToner;
	}
	void show() {
		cout << "레이저 : " << getmodel() << ", " << getmanufacturer() << ", 남은 종이 " << getavailableCount() << "장, 남은 토너" << availableToner << endl;
	}
	int getToner() {
		return availableToner;
	}
};
int main() {
	int sc; //프린터 선택
	int c; // 매수
	char yn = 'y';

	InkJetPrinter ink("Officejet V40", "HP", 5, 10);
	laserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다." << endl;
	ink.show();
	laser.show();

	while (true) {
		cout << endl << endl;
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>"; cin >> sc >> c;
		if (sc == 1) { //잉크젯 출력
			if (c <= ink.getInk()) {
				ink.print(c);
			}
			else {
				cout << "잉크가 부족합니다." << endl;
			}
		}
		else if (sc == 2) { //레이저 출력
			if (c <= laser.getToner()) {
				laser.print(c);
			}
			else {
				cout << "토너가 부족합니다." << endl;
			}
		}
		ink.show();
		laser.show();
		cout << "계속 프린트 하시겠습니까(y/n)>>"; cin >> yn;
		if (yn == 'n') {
			break;
		}
	}
}