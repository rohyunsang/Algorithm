#include <iostream>

using namespace std;

int n;
int dp[1001];

int main() {
	cin >> n;

	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;

	for (int i = 5; i <= n; i++) {
		if (dp[i - 1] * dp[i - 3] * dp[i - 4] == 0) // if any element is 0
			dp[i] = 1;
		else
			dp[i] = 0;
	}

	if (dp[n] == 1)
		cout << "SK";
	else
		cout << "CY";

	return 0;
}

// pick 1, 3, 4
// Dynamic Programming 
