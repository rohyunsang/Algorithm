#include <iostream>

using namespace std;

// DP
int dp[1001];

int main() {

	int n;

	cin >> n;
	dp[0] = 1; // n is 1 
	dp[1] = 2;


	for (int i = 2; i < n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n-1];


	return 0;
}


// 