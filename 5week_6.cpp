#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	string stop = "exit";

	do{
		cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�.)" << endl << ">>";
		getline(cin, str, '\n');

		if (str == stop){
			break;
		}
		else{
			for (int i = str.length(); i >= 0; i--){
				cout << str[i];
			}
		}
	} while (true);
}