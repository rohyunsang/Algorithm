#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int N = s1.length(), M = s2.length();
    vector<int> dp(M + 1, 0);
    vector<vector<int>> trace(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        int prev = 0;
        for (int j = 1; j <= M; j++)
        {
            int temp = dp[j];
            if (s1[i - 1] == s2[j - 1])
            {
                dp[j] = prev + 1;
                trace[i][j] = 1;
            }
            else if (dp[j] < dp[j - 1])
            {
                dp[j] = dp[j - 1];
                trace[i][j] = 2;
            }
            else
            {
                trace[i][j] = 3;
            }
            prev = temp;
        }
    }

    // ¿ªÃßÀû (Backtracking)
    string result = "";
    int i = N, j = M;
    while (i > 0 && j > 0)
    {
        if (trace[i][j] == 1)
        {
            result = s1[i - 1] + result;
            i--; j--;
        }
        else if (trace[i][j] == 2)
            j--;
        else
            i--;
    }

    cout << dp[M] << '\n';
    cout << result << '\n';
}
