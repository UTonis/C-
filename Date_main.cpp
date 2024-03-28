#include <iostream>
using namespace std;

#include "Date.h";

int main(){
	Date birth(2014, 3, 20); //2014³â 3¿ù 20ÀÏ
	Date independenceDay("1945/8/15");
	independenceDay.show();

	cout << birth.getYear() << "," << birth.getMonth() << "," << birth.getDay() << endl;

	return 0;
}