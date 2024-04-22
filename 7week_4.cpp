#include <iostream>
using namespace std;

class MyVector{
	int *mem;
	int size;
public:
	MyVector(int n = 100, int val = 0){
		mem = new int[n];
		size = n;
		for (int i = 0; i < size; i++){
			mem[i] = val;
		}
	}
	~MyVector() { delete[] mem; }
	void show(){
		for (int i = 0; i < size; i++) { cout << mem[i]; }
	}
};


int main(){
	MyVector mem1;
	MyVector mem2(1);
	MyVector mem3(1, 2);

	mem1.show();
	cout << endl;
	mem2.show();
	cout << endl;
	mem3.show();
	cout << endl;
}