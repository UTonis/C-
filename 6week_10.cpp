#include <iostream>
#include <string>
using namespace std;
class Histogram{
	string text;
public:
	Histogram(){};
	Histogram(string text) {
		this->text = text;
	} 
	void put(string text){
		this->text.append(text);
	}
	void putc(char text){
		this->text += text;
	}
	void print(){
		cout << endl << endl;
		int n[26] = { 0 };
		cout << text << endl;
		int len = 0;
		for (int i = 0; i < text.length(); i++){
			text[i] = tolower(text[i]);
			if (text[i] >= 'a' && text[i] <= 'z')
				len++;
		}
		cout << "ÃÑ ¾ËÆÄºª ¼ö " << len << endl;
		for (int i = 0; i < text.length(); i++){
			for (char c = 'a'; c <= 'z'; c++){
				if (text[i] == c){
					n[(int)c - 97]++;
				}
			}
		}
		for (int i = 0; i < 26; i++){
			cout << (char)(i + 97) << "  (" << n[i] << ")  : ";
			for (int j = 0; j < n[i]; j++){
				cout << '*';
			}
			cout << endl;
		}

	}
};

int main(){
	Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}