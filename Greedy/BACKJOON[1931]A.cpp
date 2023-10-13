#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int n;
	cin >> n;
	int ans = 0;
	int endTime = 0;

	vector<pair<int,int>> v;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ y,x });
	}

	sort(v.begin(), v.end());

	endTime = v[0].first;
	ans++;

	for (int i = 1; i < n; i++) {
		if (endTime <= v[i].second) {
			ans++;
			endTime = v[i].first;
		}
	}


	cout << ans;

	return 0;
}