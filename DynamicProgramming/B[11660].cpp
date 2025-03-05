#include<iostream>

using namespace std;

#define MAX 1025

int table[MAX][MAX];
int dp[MAX][MAX];
int n, m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int ans;

	int x1, x2, y1, y2;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int x;
			cin >> x;

			if (i == 1 && j == 1) dp[i][j] = x;
			else if (i == 1)
			{
				dp[i][j] = x + dp[i][j - 1];
			}
			else if (j == 1)
			{
				dp[i][j] = x + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = x + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
			}
		}


	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		ans = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << ans << '\n';
	}

}