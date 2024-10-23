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

	long long ans = 0;

	int start = 0;
	int end = v.back();

	while (start <= end) {
		int mid = (start + end) / 2;

		long long sum = 0;
		for (auto _v : v) {
			if (_v > mid) {
				sum += (_v - mid);
			}
		}

		if (sum >= m) {  // sum 이 더클경우 mid를 높여야한다. 
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans;


	return 0;
}