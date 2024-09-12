#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector<long long> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long ans1 = 0, ans2 = 0, ans3 = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	long long sum = 3123456789;
	

	for (int i = 0; i < n - 2; i++) {
		long long start = i + 1;
		long long end = n - 1;
		while (start < end) {
			if (sum > abs(v[i] + v[start] + v[end])) {
				sum = abs(v[i] + v[start] + v[end]);
				ans1 = v[i];
				ans2 = v[start];
				ans3 = v[end];
			}
			if (v[i] + v[start] + v[end] < 0) {
				start++;
			}
			else
				end--;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3;

	return 0;
}

