#include <iostream>
using namespace std;

class CoffeeMachine{
public:
	int Coffee, Water, Sugar;
	CoffeeMachine(int a, int b, int c);
	int drinkEspresso();
	int drinkAmericano();
	int drinkSugarCoffee();
	int fill();
	void show();
};

CoffeeMachine::CoffeeMachine(int a, int b, int c){
	Coffee = a;
	Water = b;
	Sugar = c;
}

int CoffeeMachine::drinkEspresso(){
	Coffee = Coffee - 1;
	Water = Water - 1;

	return 0;
}

int CoffeeMachine::drinkAmericano(){
	Coffee = Coffee - 1;
	Water = Water - 2;

	return 0;
}

int CoffeeMachine::drinkSugarCoffee(){
	Coffee = Coffee - 1;
	Water = Water - 2;
	Sugar = Sugar - 1;

	return 0;
}

int CoffeeMachine::fill(){
	Coffee = 10;
	Water = 10;
	Sugar = 10;

	return 0;
}

void CoffeeMachine::show(){
	cout << "Ŀ�� �ӽ� ����, Ŀ��:" << Coffee << "  ��:" << Water << "  ����:" << Sugar << endl;
}

int main(){
	CoffeeMachine java(5, 10, 3);  // Ŀ�� 5, ���� 10, ���� 6 ���� �ʱ�ȭ
	java.drinkEspresso();  // Ŀ�� 1, �� 1 �Һ�
	java.show();  //���� Ŀ�Ǹӽ� ���� ���
	java.drinkAmericano();  // Ŀ��1 , �� 2 �Һ�
	java.show();
	java.drinkSugarCoffee(); // Ŀ�� 1, �� 2, ���� 1 �Һ�
	java.show();
	java.fill();  // Ŀ�� 10, �� 10, ���� 10���� ä���
	java.show();
}