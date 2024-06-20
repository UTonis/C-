#include <iostream>
using namespace std;
template <class T>
bool equalArrays(T x[], T y[], int s) {
	bool b = true;
	for (int i = 0; i < s; i++) {
		if (x[i] != y[i]) {
			b = false;
		}
	}
	return b;
};
int main() {
	int x[] = { 1, 10, 100, 5, 4 };
	int y[] = { 1, 10, 100, 5, 4 };
	if (equalArrays(x, y, 5)) cout << "같다";
	else cout << "다르다";
}