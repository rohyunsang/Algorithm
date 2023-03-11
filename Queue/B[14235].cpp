#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;

priority_queue<int> q;

int main() {
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (a == 0) {
			if (q.size() == 0) {
				cout << "-1" << endl;
			}
			else
			{
				cout << q.top() << endl;
				q.pop();
			}
		}
		else {
			while (a--) {
				int nTmp;
				cin >> nTmp;
				q.push(nTmp);
			}
		}
	}


	return 0;
}