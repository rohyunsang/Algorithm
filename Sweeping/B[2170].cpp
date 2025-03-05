#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int ans = 0;
	int n;
	cin >> n;

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	int left = v[0].first;
	int right = v[0].second;

	for (auto v : v) {
		if (right >= v.first) {
			right = max(right, v.second);
		}
		else {
			ans += (right - left);
			left = v.first;
			right = v.second;
		}
	}

	ans += (right - left);
	cout << ans;

	return 0;
}