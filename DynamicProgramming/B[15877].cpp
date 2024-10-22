#include <iostream>

using namespace std;

// method 1 : take 1 banana
// method 2 : take 1 apple
// method 3 : take 1 apple, 3 banana
// method 4 : take 3 apple, 1 banana

#define MAX 1001

bool dp[MAX][MAX] = { false };

int main() {

	int appleCnt;
	int bananaCnt;
	cin >> appleCnt >> bananaCnt;

	if (appleCnt == bananaCnt && bananaCnt == 0)
	{
		cout << "Bob";
		return 0;
	}
	dp[0][0] = false;

	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = false;
			if (i - 1 >= 0 && j - 3 >= 0)
				if (dp[i - 1][j - 3] == false) dp[i][j] = !dp[i - 1][j - 3];
			if (j - 1 >= 0 && i - 3 >= 0)
				if (dp[i - 3][j - 1] == false) dp[i][j] = !dp[i - 3][j - 1];
			if (j - 1 >= 0) {
				if (!dp[i][j - 1]) dp[i][j] = true;
			}
			if (i - 1 >= 0)
				if (!dp[i - 1][j]) dp[i][j] = true;
		}
	}


	if(dp[appleCnt][bananaCnt])
		cout << "Alice";
	else
		cout << "Bob";


	return 0;
}