#include <iostream>
using namespace std;
class SortedArray{
	int size;
	int *p;
	void sort(){
		int tmp;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (p[j] > p[j + 1]) {
					tmp = p[j];
					p[j] = p[j + 1];
					p[j + 1] = tmp;
				}
			}
		}
	}
public:
	SortedArray(){ size = 0; p = NULL; }
	SortedArray(SortedArray& src){
		size = src.size;
		p = new int[size];
		for (int i = 0; i < size; i++) {
			p[i] = src.p[i];
		}
	}
	SortedArray(int p[], int size){
		this->size = size;
		this->p = new int[size];
		for (int i = 0; i < size; i++){
			this->p[i] = p[i];
		}

		sort();
	}
	~SortedArray() { delete[] p; }
	SortedArray operator + (SortedArray& op2){
		SortedArray tmp;
		tmp.size = this->size + op2.size;
		tmp.p = new int[tmp.size];
		for (int i = 0; i < this->size; i++){
			tmp.p[i] = this->p[i];
		}
		for (int i = size; i < tmp.size; i++){
			tmp.p[i] = op2.p[i - size];
		}
		sort();
		return tmp;
	}
	SortedArray operator = (const SortedArray& op2){
		this->size = op2.size;
		delete[] this->p;
		p = new int[size];
		for (int i = 0; i < size; i++){
			this->p[i] = op2.p[i];
		}
		sort();
		return *this;
	}
	void show(){
		cout << "배열 출력 :  ";
		for (int i = 0; i < size; i++){
			cout << p[i] << ' ';
		}
		cout << endl;
	}
};
int main(){
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;

	a.show();
	b.show();
	c.show();
}