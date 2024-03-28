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
	cout << "커피 머신 상태, 커피:" << Coffee << "  물:" << Water << "  설탕:" << Sugar << endl;
}

int main(){
	CoffeeMachine java(5, 10, 3);  // 커피 5, 물량 10, 설탕 6 으로 초기화
	java.drinkEspresso();  // 커피 1, 물 1 소비
	java.show();  //현재 커피머신 상태 출력
	java.drinkAmericano();  // 커피1 , 물 2 소비
	java.show();
	java.drinkSugarCoffee(); // 커피 1, 물 2, 설탕 1 소비
	java.show();
	java.fill();  // 커피 10, 물 10, 설탕 10으로 채우기
	java.show();
}