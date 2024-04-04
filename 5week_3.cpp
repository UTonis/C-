#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	int Index = 0;
	int count = 0;

	cout << "문자열 입력>> ";
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
	
	cout << "문자 a는 " << count << "개 있습니다.";
}