#include <iostream>
#include <string>
using namespace std;

#include "Account.h"

Account::Account(string N, int I, int B){
	Name = N;
	ID = I;
	Balance = B;
}

string Account::getOwer(){
	return Name;
}

int Account::inquiry(){
	return Balance;
}

int Account::deposit(int a){
	Balance = Balance + a;
	return Balance;
}

int Account::withdraw(int b){
	Balance = Balance - b;
	return Balance;
}