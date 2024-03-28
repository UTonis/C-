#include <iostream>
#include <string>
using namespace std;

#include "Account.h";

int main(){
	Account a("kitae", 1, 5000); //id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
	a.deposit(50000);  // 50000원 저금
	cout << a.getOwer() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000); // 20000원 출금, withdraw()는 출금한 실제 금액 리턴
	cout << a.getOwer() << "의 잔액은 " << a.inquiry() << endl;
}