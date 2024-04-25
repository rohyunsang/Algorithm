#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//DP

const int Max = 101;

int dp[Max][100001];
int w[101];
int v[101];

/*

 dp[0] 0
 dp[1] 0  
 dp[2] 0  
 dp[3] 6  
 dp[4] 8 // dp[i-1] 과 비교해서 v가 더 높으면   
 dp[5] 12 // dp[i-1] 과 비교해서 v가 더 높으면
 dp[6] 13 // dp[i-1] 과 비교해서 v가 더 높으면
 dp[7] 14 // dp[i-1] 과 비교해서 v가 더 높으면, dp
     

*/

/*
    dp 0 1 2 3 4 5 6 7 
 k
 1     0 0 0 0 0 0 0 0 
 2     0 0 0 0 0 0 0 0 
 3     0 0 0 6 6 6 6 6  
 4     0 0 0 6 8 8 8 8 
 5     0 0 0 6 8 121212
 6     0 0 0 6 8 121313
 7     0 0 0 6 8 121314

*/





int main() {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{

			if (j - w[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[n][k];



	return 0;
}