#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Random{
public:
	int next();
	int nextInRange(int a, int b);
};


int Random::next(){
	return rand();
}

int Random::nextInRange(int a, int b){
	do{
		int n1 = rand();
		if (n1 >= 2 && n1 <= 4){
			return n1;
		}
	} while (true);
}

int main(){
	srand((unsigned)time(0));
	int n = rand();
	Random r;
	cout << "-- 0에서" << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++){
		int n = r.next(); //  0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++){
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}