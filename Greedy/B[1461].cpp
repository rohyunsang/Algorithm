#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;
	int ans = 0;

	vector<int> v(n);

	int leftCnt = 0;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (v[i] < 0) leftCnt++;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < leftCnt; i += k) {
		ans += abs(v[i] * 2);
	}
	for (int i = n - 1; i >= leftCnt; i -= k) {
		ans += abs(v[i] * 2);
	}

	ans -= max(abs(v[0]), abs(v[v.size() - 1]));

	cout << ans;

}