#include <iostream>
#include <string>
using namespace std;
class Printer {
	string model; //�𵨸�
	string manufacturer; // ������
	int printedCount; // �μ� �ż�
	int availableCount; // �μ� ���� �ܷ�
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
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
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
	int availableInk; //��ũ �ܷ�
public:
	InkJetPrinter(string model = "", string manufacturer = "", int availableCount = 0, int availableInk = 0) : Printer(model, manufacturer, availableCount){
		this->availableInk = availableInk;
	}
	void show() {
		cout << "��ũ�� : " << getmodel() << ", " << getmanufacturer() << ", ���� ���� " << getavailableCount() << "��, ���� ��ũ" << availableInk << endl;
	}
	int getInk() {
		return availableInk;
	}
};
class laserPrinter :public Printer {
	int availableToner; // ��� �ܷ�
public:
	laserPrinter(string model = "", string manufacturer = "", int availableCount = 0, int availableToner = 0) : Printer(model, manufacturer, availableCount){
		this->availableToner = availableToner;
	}
	void show() {
		cout << "������ : " << getmodel() << ", " << getmanufacturer() << ", ���� ���� " << getavailableCount() << "��, ���� ���" << availableToner << endl;
	}
	int getToner() {
		return availableToner;
	}
};
int main() {
	int sc; //������ ����
	int c; // �ż�
	char yn = 'y';

	InkJetPrinter ink("Officejet V40", "HP", 5, 10);
	laserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����." << endl;
	ink.show();
	laser.show();

	while (true) {
		cout << endl << endl;
		cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>>"; cin >> sc >> c;
		if (sc == 1) { //��ũ�� ���
			if (c <= ink.getInk()) {
				ink.print(c);
			}
			else {
				cout << "��ũ�� �����մϴ�." << endl;
			}
		}
		else if (sc == 2) { //������ ���
			if (c <= laser.getToner()) {
				laser.print(c);
			}
			else {
				cout << "��ʰ� �����մϴ�." << endl;
			}
		}
		ink.show();
		laser.show();
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>"; cin >> yn;
		if (yn == 'n') {
			break;
		}
	}
}