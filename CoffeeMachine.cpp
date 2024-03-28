#include <iostream>
using namespace std;

#include "CoffeeMachine.h";

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
