#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[1001];
vector<int> v;

// DP

int main() {
	cin >> n;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] < v[j])
			{
				dp[j] = max(dp[i] + 1, dp[j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		
		if (ans < dp[i])
			ans = dp[i];
	}

	cout << ans;
	
	return 0;
}