#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Dynamic Programming ? 

string s1;
string s2;
int dp[1000 + 1][1000 + 1] = { 0, };

int main() {
	cin >> s1;
	cin >> s2;

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[s1.size()][s2.size()];

	return 0;
}