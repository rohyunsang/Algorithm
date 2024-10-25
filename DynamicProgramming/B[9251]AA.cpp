#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1001
int dp[MAX][MAX] = { 0 };

int main() {
	string s1;
	string s2;
	cin >> s1 >> s2;

	int s1Size = (int)s1.size();
	int s2Size = (int)s2.size();

	for (int i = 1; i <= s1Size; i++) {
		for (int j = 1; j <= s2Size; j++) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	/*
	for (int i = 1; i <= s1Size; i++) {
		for (int j = 1; j <= s2Size; j++) {
			cout << dp[i][j];
		}
		cout << endl;
	}
	*/
	cout << dp[s1Size][s2Size];

	return 0;
}


/*

	
	  i A C A Y K P 
	j
	C   0 1 1 1 1 1
	A   1 1 2 2 2 2
	P   1 1 2 2 2 3
	C   1 2 2 2 2 3
	A   2 2 3 3 3 3
	K   2 2 3 3 4 4 

	001111
	111222
	111222
	111233
	122233
	122234
*/