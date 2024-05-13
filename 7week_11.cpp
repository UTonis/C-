#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;
class GamblingGame{
	string name[2];
	int num[3];
public:
	GamblingGame(){ srand((unsigned)time(0)); };
	void run(){
		string buf;
		cout << "***** 갬블링 게임을 시작합니다. *****" << endl;
		cout << "첫번째 선수 이름 >>";
		cin >> name[0];
		cout << "두번째 선수 이름 >>";
		cin >> name[1];
		int i = 0;
		getline(cin, buf, '\n');
		while (true){
			if (i % 2 == 0){
				cout << name[i % 2] << ": <Enter>";
				getline(cin, buf, '\n');
				for (int i = 0; i < 3; i++){
					num[i] = rand() % 3;
					cout << "                " << num[i];
				}
				if (num[0] == num[1] && num[1] == num[2]){
					cout << "                " << name[i % 2] << "님 승리!!" << endl;
					break;
				}
				else{
					cout << "                아쉽군요!" << endl;
				}
				i++;
			}
			else if (i % 2 == 1){
				cout << name[i % 2] << ": <Enter>";
				getline(cin, buf, '\n');
				for (int i = 0; i < 3; i++){
					num[i] = rand() % 3;
					cout << "                " << num[i];
				}
				if (num[0] == num[1] && num[1] == num[2]){
					cout << "                " << name[i % 2] << "님 승리!!" << endl;
					break;
				}
				else{
					cout << "                아쉽군요!" << endl;
				}
				i++;
			}
		}
	}
};

int main(){
	GamblingGame g;
	g.run();
}