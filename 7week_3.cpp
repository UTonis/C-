#include <iostream>
using namespace std;

int big(int a, int b, int c = -1){
	if (c > 0){
		if (a > b){
			if (b > c){ // a b c
				return b;
			}
			else{ // a c b
				return c;
			}
		}
		else{
			if (a > c){ // b a c
				return a;
			}
			else{  //b c a
				return c;
			}
		}
	}
	else{
		if (a > b){
			if (a > 100){
				return 100;
			}
			else{
				return a;
			}
		}
		else{
			if (b > 100){
				return 100;
			}
			else{
				return b;
			}
		}
	}
}

int main(){
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
}