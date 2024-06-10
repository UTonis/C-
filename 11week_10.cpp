#include <iostream>
using namespace std;
class Statistics{
	int size;
	int *num;
public:
	Statistics(int size = 0){ this->size = size; num = new int[size]; }
	~Statistics(){ delete[] num; }
	bool operator !(){
		if (size == 0)
			return true;
		else
			return false;
	}
	Statistics& operator << (int x){
		size++;
		Statistics tmp(size);
		for (int i = 0; i < size - 1; i++){
			tmp.num[i] = this->num[i];
		}
		tmp.num[size - 1] = x;
		delete[] this->num;

		num = new int[size];
		for (int i = 0; i < size; i++){
			this->num[i] = tmp.num[i];
		}
		return *this;
	}
	void operator ~(){
		for (int i = 0; i < size; i++){
			cout << num[i] << ' ';
		}
		cout << endl;
	}
	void operator >> (int &x){
		int sum = 0;
		for (int i = 0; i < size; i++){
			sum += num[i];
		}

		x = sum / size;
	}
};
int main(){
	Statistics stat;
	if (!stat) cout << "현재 통계 테이타가 없습니다." << endl;

	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) cin >> x[i];

	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;
}