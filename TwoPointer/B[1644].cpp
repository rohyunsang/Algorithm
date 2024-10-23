#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;

void eratos(int n) {
	vector<bool> prime(n + 1, true);

	for (int i = 2; i * i <= n; ++i) {
		if (prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= n; ++i) {
		if (prime[i]) v.push_back(i);
	}
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}
	eratos(n);

	int start = 0;
	int end = 0;
	long long sum = 0;
	int ans = 0;

	int vSize = (int)v.size();

	while (end <= vSize) {
		if (sum < n ) {
			sum += v[end];
			end++;
		}
		else if (sum >= n) {
			sum -= v[start];
			start++;
		}
		if (sum == n) ans++;
	}
	cout << ans;

	return 0;
}

// two pointer 

