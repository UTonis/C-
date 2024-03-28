#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Random.h";

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