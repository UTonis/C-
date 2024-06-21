#include <iostream>
using namespace std;
template <class T>
void reverseArray(T x[], int s) {
	T *arr = new T[s];
	for (int i = 0; i < s; i++) {
		arr[i] = x[i];
	}

	for (int i = 0; i < s; i++) {
		x[i] = arr[s - i - 1];
	}
}
int main() {
	int x[] = { 1, 10, 100, 5 ,4 };
	reverseArray(x, 5);
	for (int i = 0; i < 5; i++)cout << x[i] << ' ';
}