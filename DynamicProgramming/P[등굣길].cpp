#include <string>
#include <vector>

using namespace std;

#define MAX 101

int dp[MAX][MAX] = { 0 };


int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    for (auto p : puddles) {
        dp[p[0]][p[1]] = -1;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            else if (dp[i][j] != -1) {
                int sum = 0;
                sum += dp[i - 1][j] != -1 ? dp[i - 1][j] : 0;
                sum += dp[i][j - 1] != -1 ? dp[i][j - 1] : 0;
                dp[i][j] = sum % 1000000007;
            }
        }
    }

    answer = dp[m][n];

    return answer;
}

// 오른쪽 x 3, 아래 x 2

// arr[i][j] = arr[i-1][j] + arr[i][j-1] 