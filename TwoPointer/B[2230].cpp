#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int start;
	int end;

	start = 0;
	end = 0;

	int ans = 2123456789;

	while (start < n && end < n) {
		int cal = v[end] - v[start];
		if (cal < m)
			end++;
		else
		{
			ans = min(ans, cal);
			start++;
		}
	}

	cout << ans;


	return 0;
}