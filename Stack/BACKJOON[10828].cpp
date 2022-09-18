#include <iostream>
#include <stack>  //FILO

using namespace std;

stack<int> s;

int n;

int main() {
	cin >> n;

	string s_tmp;
	int i_tmp;
	while (n--) {
		cin >> s_tmp;

		// push
		if (s_tmp == "push")
		{
			cin >> i_tmp;
			s.push(i_tmp);
		}

		// pop
		if (s_tmp == "pop") {
			if (s.empty()) cout << "-1" <<endl ;
			else {
				cout << s.top() << endl;
				s.pop();
			}
		}

		// size
		if (s_tmp == "size") cout << s.size() << endl;

		// empty
		if (s_tmp == "empty") {
			if (s.empty()) cout << "1" << endl;
			else cout << "0" << endl;
		}
			

		// top
		if (s_tmp == "top") {
			if (s.empty()) cout << "-1" << endl;
			else cout << s.top() << endl;
		}

	}

	return 0;
}