#include <stack>
#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
	stack<char> c;

	while (true) {

		getline(cin, str);  //#include <string>  use push_back

		if (str[0] == '.') break;

		for (int i = 0; i < str.length() - 1; i++) {
			
			if (str[i] == '(') c.push('(');
			if (str[i] == '[') c.push('[');
			if (str[i] == ']') {
				if (!c.empty() && c.top() == '[') c.pop();
				else {
					cout << "no" << '\n';
					break;
				}
			}
			if (str[i] == ')') {
				if (!c.empty() && c.top() == '(') c.pop();
				else {
					cout << "no" << '\n';
					break;
				}
			}
			
			if (c.empty() && i == str.length() - 2) cout << "yes" << '\n';
			else if (!c.empty() && i == str.length() - 2) cout << "no" << '\n';
			
		}

	}
	

	return 0;
}
