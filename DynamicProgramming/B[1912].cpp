#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
int dp[100001] = { 0, };

int res = 0;

//Dynamic Programming 

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}

	dp[0] = v[0];
	int res = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		res = max(res, dp[i]);
	}
	cout << res;

	return 0;
}