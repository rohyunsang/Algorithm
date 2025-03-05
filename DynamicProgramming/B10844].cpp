#include <iostream>
#include <vector>

using namespace std;

#define MAX 101
int dp[MAX][10] = {0};

int main() {
	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][0] = dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][9] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= 1000000000;
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result = (result + dp[n][i]) % 1000000000;
	}

	cout << result;


	return 0;
}


// 앞이 0이면 1 가능
// 앞이 9이면 8가능
// 앞이 12345678 이면 다 가능 