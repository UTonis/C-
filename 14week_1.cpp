#include <iostream>
using namespace std;
template <class T>
T biggest(T x[], int s) {
	T big = x[0];
	for (int i = 1; i < s; i++) {
		if (big < x[i])
			big = x[i];
	}
	return big;
}

int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	cout << biggest(x, 5) << endl;
}