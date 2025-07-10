#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;

int dx[4] = { 1,-1,0,0 };    // ��, �� , �� 
int dy[4] = { 0, 0,-1 ,1};

int map[501][501] = { 0, };
int dp[501][501];

int dfs(int x, int y) {
	if (x == n - 1 && y == m - 1) return 1;

	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = 0;  // ���� ��ġ���� ����ϴ� ��� �� �ʱ�ȭ. 

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		if (map[nx][ny] < map[x][y])
		{
			dp[x][y] += dfs(nx, ny);
			// ���� ��ġ���� ���� ��ġ�� �� �� �ִٸ�,
			// �� ���� ��ġ���� ���������� �� �� �ִ� ��� ���� ���� 
		}
	}

	return dp[x][y];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin >> n >> m;

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << dfs(0, 0);

	return 0;
}