#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	int Index = 0;
	int count = 0;

	cout << "���ڿ� �Է�>> ";
	getline(cin, str, '\n');

	for (int i = Index; i < str.length(); i++){
		if (Index == -1){
			count--;
			break;
		}
		else{
			Index = str.find('a', Index + 1);
			count++;
		}
	}
	
	cout << "���� a�� " << count << "�� �ֽ��ϴ�.";
}