#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
int A[500][500];
int dp[500][500];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int dfs(int x, int y) {
    if (x == M - 1 && y == N - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    // -1 일때만 확인하는 이유는, -1이 아닐 경우 이 포인트는 이미 동서남북으로 모든 dfs를 돌고 왔기 때문이다 “dp[x][y]에 값이 들어있다는 것은, 이 칸에서 목표 지점까지 갈 수 있는 모든 경로의 개수를 이미 한 번 구해 두었다”

    // 그래서 dp[x][y] != -1이면 그 계산 결과를 재사용하면 되고, 다시 순회하면서 더할 필요 없이 그대로 return dp[x][y] 하는 겁니다.

    int cnt = 0;
    for (int d = 0; d < 4; d++)
    {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if (A[nx][ny] < A[x][y])
        {
            cnt += dfs(nx, ny);
        }
    }
    return dp[x][y] = cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            dp[i][j] = -1;  // 미방문 표시
        }
    }

    cout << dfs(0, 0) << "\n";
    return 0;
}




