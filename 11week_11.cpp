#include <iostream>
using namespace std;
class Stack{
	int index;
	int *num;
public:
	Stack(int index = 0){ this->index = index; num = new int[index]; }
	~Stack(){ delete[] num; }
	Stack& operator << (int x){
		index++;
		Stack tmp(index);
		for (int i = 0; i < index - 1; i++){
			tmp.num[i] = this->num[i];
		}
		tmp.num[index - 1] = x;
		delete[] this->num;

		num = new int[index];
		for (int i = 0; i < index; i++){
			this->num[i] = tmp.num[i];
		}
		return *this;
	}
	bool operator !(){
		if (index == 0)
			return true;
		else
			return false;
	}
	Stack& operator >> (int &x){
		x = num[index - 1];
		index = index - 1;
		return *this;
	}
	void show(){
		for (int i = 0; i < index; i++){
			cout << num[i] << ' ';
		}
		cout << endl;
	}
};

int main(){
	Stack stack;
	stack << 3 << 5 << 10;
	while (true){
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}