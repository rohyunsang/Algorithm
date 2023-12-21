#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<long long, int >> q;

int main() {
	int a, b;
	cin >> a >> b;
	int res = -1;

	q.push({ a, 1 });

	while (!q.empty()) {
		long long k = q.front().first;
		int n = q.front().second;

		q.pop();

		if (k == b) {
			res = n;
			break;
		}
		
		if (2 * k <= b)
			q.push({ k * 2,n + 1 });

		if (10 * k + 1 <= b)
			q.push({ 10 * k + 1,n + 1 });

	}

	cout << res;


	return 0;
}