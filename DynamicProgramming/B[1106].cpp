#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dp[1101];
// dp[i] => 사람이 i 명일때 최소 홍보비. 

int main() {
	int c, n;
	cin >> c >> n;

	vector<int> cost(n + 1);
	vector<int> human(n + 1);

	for (int i = 1; i <= n; i++)
	{
		cin >> cost[i] >> human[i];
	}

	int maxC = c + 100;
	const int INF = 2123456789;

	for (int h = 0; h <= maxC; ++h) dp[h] = INF;
	dp[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int h = human[i]; h <= maxC; h++)
		{
			dp[h] = min(dp[h], dp[h - human[i]] + cost[i]);
		}
	}

	int ans = INF;

	for (int h = c; h <= maxC; h++)
	{
		ans = min(ans, dp[h]);
	}

	cout << ans;


	return 0;
}