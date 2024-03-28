#include <iostream>
#include <string>
using namespace std;

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

int main(){
	Account a("kitae", 1, 5000); //id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
	a.deposit(50000);  // 50000원 저금
	cout << a.getOwer() << "의 잔액은 " << a.inquiry() << endl; 
	int money = a.withdraw(20000); // 20000원 출금, withdraw()는 출금한 실제 금액 리턴
	cout << a.getOwer() << "의 잔액은 " << a.inquiry() << endl;
}