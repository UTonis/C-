#include <iostream>
#include <string>
using namespace std;
class LoopAdder {
	string name;
	int x, y, sum;
	void read();
	void wirte();
protected:
	LoopAdder(string name = "") {
		this->name = name;
	}
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run();
};

void LoopAdder::read() {
	cout << name << ":" << endl;
	cout << "ó�� ������ �ι��� ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
	cin >> x >> y;
}

void LoopAdder::wirte() {
	cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	wirte();
}
class ForLoopAdder : public LoopAdder {
protected:
	int calculate() {
		int s = 0;
		for (int i = getX(); i <= getY(); i++) {
			s += i;
		}
		return s;
	}
public:
	ForLoopAdder(string name) : LoopAdder(name) { }
};
int main() {
	ForLoopAdder forLoop("For Loop");
	forLoop.run();
}