#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<int> dq;
int t;
string s = "";
int x;

int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		if (s == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		else if (s == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		else if (s == "pop_front") {
			if (dq.empty())
				cout << "-1" << endl;
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty())
				cout << "-1" << endl;
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (s == "size") {
			cout << dq.size() << endl;
		}
		else if (s == "empty") {
			if (dq.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (s == "front") {
			if (dq.empty())
				cout << "-1" << endl;
			else 
				cout << dq.front() << endl;

		}
		else if (s == "back") {
			if (dq.empty())
				cout << "-1" << endl;
			else 
				cout << dq.back() << endl;
		}
		
	}

	return 0;
}