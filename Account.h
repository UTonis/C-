#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account{
public:
	string Name;
	int ID, Balance;
	Account(string N, int I, int B);
	int deposit(int x);
	string getOwer();
	int inquiry();
	int withdraw(int y);
};

#endif