#include <iostream>
using namespace std;
template <class T>
bool search(int n, T x[], int s) {
	bool b = false;
	for (int i = 0; i < s; i++) {
		if (x[i] == n)
			b = true;
	}

	return b;
}
int main() {
	int x[] = { 1, 10, 100, 5 ,4 };
	if (search(100, x, 5)) cout << "100�� �迭 x�� ���ԵǾ� �ִ�";
	else cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�.";
}