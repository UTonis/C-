#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){
	string str;
	string stop = "exit";
	int index;
	int ex;
	int *p = new int[];
	int find_space[100];
	p = find_space;
	srand((unsigned)time(0));
	
	do{
		cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�.)" << endl << ">>";
		getline(cin, str, '\n');

		if (str == stop){
			break;
		}
		else{
			do{
				int n = rand();
				if (n < str.length() + 1){
					index = n;
					break;
				}
			} while (true);

			do{
				int r = rand();
				if (r > 96 && r < 123){
					ex = r;
					break;
				}
			} while (true);
			cout << str.substr(0, index) << char(ex) << str.substr(index + 1) << endl;
		}
	} while (true);
	
}