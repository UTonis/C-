#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	string stop = "exit";

	do{
		cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다.)" << endl << ">>";
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