#include <iostream>
using namespace std;
class BaseArray{
private:
	int capacity;
	int *mem;
protected:
	BaseArray(int capacity = 100){
		this->capacity = capacity;
		mem = new int[capacity];
	}
	~BaseArray(){ delete[] mem; }
	void put(int index, int val){
		mem[index] = val;
	}
	int get(int index){
		return mem[index];
	}
	void set(int index , int n){
		mem[index] = n;
	}
	int getCapacity(){
		return capacity;
	}
};
class MyStack : public BaseArray{
	int index;
public:
	MyStack(int size) { index = 0; }
	void push(int n){
		set(index, n);
		index++;
	}
	int capacity(){
		return getCapacity();
	}
	int length(){
		return index;
	}
	int pop(){
		return get(--index);
	}
};

int main(){
	MyStack mStack(100);
	int n;
	cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++){
		cin >> n;
		mStack.push(n);
	}
	cout << "���ÿ뷮:" << mStack.capacity() << ", ����ũ��:" << mStack.length() << endl;
	cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0){
		cout << mStack.pop() << ' ';
	}
	cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;
}