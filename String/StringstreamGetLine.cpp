#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string s = "";
stringstream ss;
string sTmp = "";


int main() {
	getline(cin, s); // 문자열을 한번에 받을때 이렇게 써준다.
	ss << s;
	while (ss >> sTmp) {      
		for (int i = sTmp.size() - 1; i >= 0; i--) {
			cout << sTmp[i];   
		}
		cout << " ";           

	return 0;
}