#include <iostream>
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
	cout << "처음 수에서 두번쨰 수까지 더합니다. 두 수를 입력하세요 >> ";
	cin >> x >> y;
}

void LoopAdder::wirte() {
	cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run() {
	read();
	sum = calculate();
	wirte();
}
class WhileLoopAdder : public LoopAdder {
protected:
	int calculate() {
		int s = 0;
		int i = getX();
		while(i <= getY()){
			s += i;
			i++;
		}
		return s;
	}
public:
	WhileLoopAdder(string name) : LoopAdder(name) { }
};
class DoWhileLoopAdder : public LoopAdder {
protected:
	int calculate() {
		int s = 0;
		int i = getX();
		do {
			s += i;
			i++;
		} while (i <= getY());
		return s;
	}
public:
	DoWhileLoopAdder(string name) : LoopAdder(name) { }
};

int main() {
	WhileLoopAdder whileLoop("While Loop");
	DoWhileLoopAdder doWhileLoop("Do While Loop");

	whileLoop.run();
	doWhileLoop.run();
}