#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <deque>

using namespace std;

// R : Reverse, D : Delete

int main() {
	int t;
	cin >> t;
	while (t--) {
		string func = "";
		cin >> func;
		int n;
		cin >> n;
		deque<int> dq;
		string sTmp = "";
		cin >> sTmp;
		sTmp = sTmp.substr(1, sTmp.size() - 2);

		stringstream ss(sTmp);
		string item;

		bool flag = true;
		bool isError = false;

		while (getline(ss,item,',')) {
			dq.push_back(stoi(item));
		}
		for (int i = 0; i < func.size(); i++) {
			if (func[i] == 'R') {
				flag = !flag;
			}
			else if (func[i] == 'D') {
				if (dq.size() == 0)
				{
					cout << "error" << '\n';
					isError = true;
					break;
				}
				if (flag) {
					dq.pop_front();
				}
				else {
					dq.pop_back();
				}
			}
		}
		if (!isError) {

			cout << "[";
			if (flag) {
				for (int i = 0; i < dq.size(); i++) {
					cout << dq[i];
					if (i != dq.size() - 1)
						cout << ',';
				}
			}
			else {
				for (int i = dq.size() - 1; i >= 0; i--) {
					cout << dq[i];
					if (i != 0)
						cout << ',';
				}
			}
			
			cout << "]" << '\n';
		}
		
	}



	return 0;
}