#include <iostream>
using namespace std;

char& find(char a[], char c, bool& success){
	for (int i = 0; i < 5; i++){
		if (a[i] == c){
			a[i] = c;
			success = true;
		}
	}
	return c;
}

int main(){
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false){
		cout << "M�� �߰��� �� ����." << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
}