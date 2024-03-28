#ifndef COFFEEMACHIN_H
#define COFFEEMACHIN_H

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

#endif