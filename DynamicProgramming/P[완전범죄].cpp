#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


const int INF = 987654321;

int solution(vector<vector<int>> info, int n, int m) {
	int cnt = (int)info.size();
	vector<vector<int>> dp(cnt + 1, vector<int>(m + 1, INF));

	dp[0][0] = 0;

	for (int i = 0; i < cnt; i++)
	{
		for (int j = m; j >= 0; j--)     // m을 기준으로 dp를 돌린다. 
		{
			if (dp[i][j] == INF) continue;

			if (j + info[i][1] < m)
			{
				dp[i + 1][j + info[i][1]] = min(dp[i + 1][j + info[i][1]], dp[i][j]]);
			}

			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + info[i][0]);
		}
	}

	int ans = INF;
	for (int j = 0; j < m; j++)
	{
		ans = min(ans, dp[cnt][j]);
	}



}