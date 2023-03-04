#include <iostream>
#include <vector>

using namespace std;

int dp[1002] = { 0, };
int n;
int main() {
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	//dp[4] = 5;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] % 10007 + dp[i - 2] % 10007;
	}
	cout << dp[n] % 10007;


	return 0;
}