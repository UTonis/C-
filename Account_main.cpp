#include <iostream>
#include <string>
using namespace std;

#include "Account.h";

int main(){
	Account a("kitae", 1, 5000); //id 1��, �ܾ� 5000��, �̸��� kitae�� ���� ����
	a.deposit(50000);  // 50000�� ����
	cout << a.getOwer() << "�� �ܾ��� " << a.inquiry() << endl;
	int money = a.withdraw(20000); // 20000�� ���, withdraw()�� ����� ���� �ݾ� ����
	cout << a.getOwer() << "�� �ܾ��� " << a.inquiry() << endl;
}