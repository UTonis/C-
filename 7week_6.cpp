#include <iostream>
using namespace std;

class ArrayUtility2{
public:
	static int* concat(int s1[], int s2[], int size){
		cout << "합친 정수 배열을 출력한다." << endl;
		for (int i = 0; i < size; i++){
			cout << s1[i] << ' ';
		}
		for (int i = 0; i < size; i++){
			cout << s2[i] << ' ';
		}

		return 0;
	}
	static int* remove(int s1[], int s2[], int size, int& retSize){
		int count = 0;
		for (int i = 0; i < size; i++){
			for (int y = 0; y < size; y++){
				if (s1[i] == s2[y]){
					s1[i] = NULL;
					count++;
					break;
				}
			}
		}
		cout << "개수는 " << size - count << endl;
		for (int i = 0; i < size; i++){
			if (s1[i] != NULL){
				cout << s1[i] << ' ';
			}
		}
		retSize = 5 - count;

		if (retSize == 0)
			return NULL;
		else
			return &retSize;

		return 0;
	}
};

int main(){
	int x[5], y[5];
	cout << "정수를 5개 입력하라. 배열 x에 삽입한다.";
	for (int i = 0; i < 5; i++){
		cin >> x[i];
	}
	cout << endl;
	cout << "정수를 5개 입력하라. 배열 y에 삽입한다.";
	for (int i = 0; i < 5; i++){
		cin >> y[i];
	}

	ArrayUtility2::concat(x, y, 5);
	ArrayUtility2::remove(x, y, 5, *x);
}