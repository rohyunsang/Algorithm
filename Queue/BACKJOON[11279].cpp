#include <queue>
#include <iostream>

using namespace std;

int n;
priority_queue<int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		if (tmp) {
			q.push(tmp);
		}
		else
		{
			if (q.empty()) cout << '0' << '\n';
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}
		}
	}



	return 0;
}