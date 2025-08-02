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
    // -1 �϶��� Ȯ���ϴ� ������, -1�� �ƴ� ��� �� ����Ʈ�� �̹� ������������ ��� dfs�� ���� �Ա� �����̴� ��dp[x][y]�� ���� ����ִٴ� ����, �� ĭ���� ��ǥ �������� �� �� �ִ� ��� ����� ������ �̹� �� �� ���� �ξ��١�

    // �׷��� dp[x][y] != -1�̸� �� ��� ����� �����ϸ� �ǰ�, �ٽ� ��ȸ�ϸ鼭 ���� �ʿ� ���� �״�� return dp[x][y] �ϴ� �̴ϴ�.

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
            dp[i][j] = -1;  // �̹湮 ǥ��
        }
    }

    cout << dfs(0, 0) << "\n";
    return 0;
}




