#include <iostream>
using namespace std;
class Matrix;
int *operator >> (Matrix a, int x[]);
Matrix operator << (Matrix &b, int y[]);

class Matrix{
	int num[4];
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
		num[0] = a; num[1] = b; num[2] = c; num[3] = d;
	}
	
	void show(){
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++){
			cout << num[i] << " ";
		}
		cout << "}" << endl;
	}
	friend int *operator >> (Matrix a, int x[]){
		for (int i = 0; i < 4; i++){
			x[i] = a.num[i];
		}
		return x;
	}
	friend Matrix operator << (Matrix &b, int y[]){
		for (int i = 0; i < 4; i++){
			b.num[i] = y[i];
		}
		return b;
	}
};

int main(){
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1, 2, 3, 4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++){
		cout << x[i] << ' ';
	}
	cout << endl;
	b.show();
}