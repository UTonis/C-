#include <iostream>
#include <string>
using namespace std;
class Printer{
	string model; //�� �̸�
	string manufacturer; //������
	int printedCount; //�μ� �ż�
	int availableCount; // �μ� ���� �ܷ�
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
	raserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);
	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ���� " << endl;
	cout << "��ũ�� : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
	cout << "������ : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;
	cout << endl;

	while (yn == 'y'){
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> num >> pages;

		if (num == 1){
			if (ink.getavailableCount() >= pages && ink.getavailableInk() >= pages){
				ink.printInkJet(pages);
				cout << "��ũ�� : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
				cout << "������ : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;

			}
			else{
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
				cout << "��ũ�� : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
				cout << "������ : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;

			}
		}
		else if (num == 2){
			if (laser.getavailableCount() >= pages && laser.getavailableToner() >= pages){
				laser.printLaser(pages);
				cout << "��ũ�� : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
				cout << "������ : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;
			}
			else{
				cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
				cout << "��ũ�� : " << ink.getModel() << ", " << ink.getmanufacturer() << ", " << ink.getavailableCount() << ", " << ink.getavailableInk() << endl;
				cout << "������ : " << laser.getModel() << ", " << laser.getmanufacturer() << ", " << laser.getavailableCount() << ", " << laser.getavailableToner() << endl;

			}
		}
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> yn;

		cout << endl << endl;
	}

}