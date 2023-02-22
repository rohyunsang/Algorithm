#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

priority_queue<long long, vector<long long>, greater<long long>> q;

int main() {
	cin >> n >> m;
	long long ans = 0;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		q.push(tmp);
	}

	for (int i = 0; i < m; i++) {
		long long sum = 0;
		sum += q.top();
		q.pop();
		sum += q.top();
		q.pop();
		q.push(sum);
		q.push(sum);
	}
	
	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}

	cout << ans;

	return 0;
}