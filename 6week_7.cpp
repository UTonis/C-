#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];
	int tos;
public:
	MyIntStack(){ tos = 0; for (int i = 0; i < 10; i++){ p[i] = NULL; } }
	bool push(int n); 
	bool pop(int &n);
};

bool MyIntStack::push(int n){
	if (p[n] == NULL){
		p[n] = n;
		tos++;
		return true;
	}
	else{
		return false;
	}
}

bool MyIntStack::pop(int &n){
	if (p[tos] != NULL){
		p[tos] = tos;
		tos--;
		n = tos;
		return true;
	}
	else{
		return false;
	}
}

int main(){
	MyIntStack a;
	for (int i = 0; i < 11; i++){
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << "번째 stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++){
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}