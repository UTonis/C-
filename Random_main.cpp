#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Random.h";

int main(){
	srand((unsigned)time(0));
	int n = rand();
	Random r;
	cout << "-- 0����" << RAND_MAX << "������ ���� ���� 10��--" << endl;
	for (int i = 0; i < 10; i++){
		int n = r.next(); //  0���� RAND_MAX(32767) ������ ������ ����
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "4 ������ ���� ���� 10�� --" << endl;
	for (int i = 0; i < 10; i++){
		int n = r.nextInRange(2, 4); // 2���� 4 ������ ������ ����
		cout << n << ' ';
	}
	cout << endl;
}