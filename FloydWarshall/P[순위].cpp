// 플로이드 워셜 알고리즘
// 기본 점화식 Dab = min(Dab, Dak + Dkb) 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool dp[101][101] = { false };

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	for (int i = 0; i < results.size(); i++) {
		dp[results[i][0]][results[i][1]] = true;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][k] == true && dp[k][j] == true) {
					dp[i][j] = true;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == true || dp[j][i] == true) cnt++;
		}
		if (cnt == n - 1)
			answer++;
	}


	return answer;
}