#include <iostream>
#include <queue>

using namespace std;

int n, k;  // n, k <= 1,000
queue<int> q;

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	

	cout << '<';
	int cnt = 1;

	while (!q.empty()) {

		if (cnt % k == 0) {
			int a = q.front();
			q.pop();
			if (q.empty())
			{
				cout << a << ">"; // '>' error
			}
			else {
				cout << a << ", ";
			}
		}
		else {
			int num = q.front();
			q.pop();
			q.push(num);
		}

		cnt++;
	}

	return 0;
}

