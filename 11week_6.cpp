#include <iostream>
using namespace std;
class Matrix;
Matrix operator + (Matrix a, Matrix b);
Matrix operator += (Matrix &a, Matrix b);
bool operator == (Matrix a, Matrix c);

class Matrix{
	int num[4];
public:
	Matrix(int a = 0, int b = 0, int c = 0, int d = 0){
		num[0] = a; num[1] = b; num[2] = c; num[3] = d;
	}
	friend Matrix operator + (Matrix a, Matrix b){
		Matrix tmp;
		for (int i = 0; i < 4; i++){
			tmp.num[i] = a.num[i] + b.num[i];
		}
		return tmp;
	}
	friend Matrix operator += (Matrix &a, Matrix b){
		for (int i = 0; i < 4; i++){
			a.num[i] += b.num[i];
		}
		return a;
	}
	friend bool operator == (Matrix a, Matrix c){
		for (int i = 0; i < 4; i++){
			if (a.num[i] != c.num[i]){
				return false;
				break;
			}
		}
		return true;
	}
	void show(){
		cout << "Matrix = { ";
		for (int i = 0; i < 4; i++){
			cout << num[i] << " ";
		}
		cout << "}" << endl;
	}
};

int main(){
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c){
		cout << "a and c are the same" << endl;
	}
}