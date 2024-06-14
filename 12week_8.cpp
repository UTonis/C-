#include <iostream>
#include <string>
using namespace std;
class Printer{
	string model; //모델 이름
	string manufacturer; //제조사
	int printedCount; //인쇄 매수
	int availableCount; // 인쇄 종이 잔량
public:
	Printer(){ printedCount = 0; availableCount = 0; }
	void print(int pages){
		availableCount = availableCount - pages;
		printedCount += pages; 
	}
	void setModel(string model) { this->model = model; }
	string getModel() { return model; }
	void setmanufacturer(string manufacturer) { this->manufacturer = manufacturer; }
	string getmanufacturer() { return manufacturer; }
	void setavailableCount(int availableCount){
		this->availableCount = availableCount;
	}
	int getavailableCount(){ return availableCount; }
};
class InkPrinter : public Printer{
	int availableInk;
public:
	InkPrinter(string model, string manufacturer, int availableCount, int availableInk){
		setModel(model);
		setmanufacturer(manufacturer);
		setavailableCount(availableCount);
		this->availableInk = availableInk;
	}
	int getavailableInk(){ return availableInk; }
	void printInkJet(int pages){
		print(pages);
		availableInk -= pages;
	}
};
class raserPrinter : public Printer{
	int availableToner;
public:
	raserPrinter(string model, string manufacturer, int availableCount, int availableToner){
		setModel(model);
		setmanufacturer(manufacturer);
		setavailableCount(availableCount);
		this->availableToner = availableToner;
	}
	int getavailableToner(){ return availableToner; }
	void printLaser(int pages){
		print(pages);
		availableToner -= pages;
	}
};
int main(){
	int num;
	int pages;
	char yn = 'y';

	InkPrinter ink("Officejet V40", "HP", 5, 10);
	raserPrinter laser("SCX-6x45", "삼성전자", 3, 20);
	cout << "현재 작동중인 2 대의 프린터는 아래와 같다 " << endl;
	cout << "잉크젯 : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
	cout << "레이저 : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;
	cout << endl;

	while (yn == 'y'){
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> num >> pages;

		if (num == 1){
			if (ink.getavailableCount() >= pages && ink.getavailableInk() >= pages){
				ink.printInkJet(pages);
				cout << "잉크젯 : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
				cout << "레이저 : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;

			}
			else{
				cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
				cout << "잉크젯 : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
				cout << "레이저 : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;

			}
		}
		else if (num == 2){
			if (laser.getavailableCount() >= pages && laser.getavailableToner() >= pages){
				laser.printLaser(pages);
				cout << "잉크젯 : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
				cout << "레이저 : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;
			}
			else{
				cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
				cout << "잉크젯 : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
				cout << "레이저 : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;

			}
		}
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> yn;

		cout << endl << endl;
	}

}