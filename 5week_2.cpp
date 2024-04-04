#include <iostream>
using namespace std;

int main(){
	double *p = new double[5];

	cout << "정수 5개 입력: ";
	cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4];

	cout << "평균 " << (p[0] + p[1] + p[2] + p[3] + p[4]) / 5;
}