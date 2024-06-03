#include <iostream>
#include <string>
#include <algorithm>
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
	int getCapacity(){
		return capacity;
	}
};
class MyQueue : public BaseArray{
	int index;
public:
	MyQueue(){ 
		index = 0;
		for (int i = 0; i < 100; i++){
			put(i, 0);
		}
	}
	MyQueue(int n){
		index = 0; 
		for (int i = 0; i < 100; i++){
			put(i, 0);
		}
	}
	void enqueue(int n){
		put(index, n);
		index++;
	}
	int capacity(){
		return getCapacity();
	}
	int dequeue(){
		put(index, 0);
		index = index - 1;
		return get(index);
	}
	int length(){
		return index;
	}
};

int main(){
	MyQueue mQ(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�.";
	for (int i = 0; i < 5; i++){
		cin >> n;
		mQ.enqueue(n);
	}
	cout << "ť�� �뷮:" << mQ.capacity() << ", ť�� ũ��:" << mQ.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>>";
	while (mQ.length() != 0){
		cout << mQ.dequeue() << ' ';
	}
	cout << endl << "ť�� ���� ũ�� : " << mQ.length() << endl;
}