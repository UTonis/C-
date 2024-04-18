#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big){
	if (a > b){
		big = a;
			return false;
	}
	else if (b > a){
		big = b;
		return false;
	}
	else{
		return true;
	}
}

int main(){
	int n1, n2, max;
	cout << "두 정수 입력 >>";
	cin >> n1 >> n2;
	
	if (bigger(n1, n2, max) != true){
		cout << max << "가 더 큽니다.";
	}
	else{
		cout << "같습니다.";
	}
	
}