#include <iostream>
using namespace std;

int main(){
	double *p = new double[5];

	cout << "���� 5�� �Է�: ";
	cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4];

	cout << "��� " << (p[0] + p[1] + p[2] + p[3] + p[4]) / 5;
}