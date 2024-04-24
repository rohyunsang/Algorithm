#include <iostream>
#include <queue>

using namespace std;
int n;
int res = 0;
int map[17][17];
const int WIDTH = 0;
const int DIAGONAL = 1;
const int HEIGHT = 2;
// 
queue<pair<pair<int,int>, int>> q;

int dx[3] = { 0,1,1, }; // 가로 대각선 세로
int dy[3] = { 1,1,0 }; 

void dfs(int row, int col, int dir) {

	if (row == n && col == n)
	{
		res++;
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (dir == WIDTH && i == HEIGHT)
			continue;
		if (dir == HEIGHT && i == WIDTH)
			continue;

		int nr = row + dx[i];
		int nc = col + dy[i];

		if (row < 1 || row > n || col < 1 || col > n || map[nr][nc] == 1)
			continue;
		if (i == DIAGONAL && (map[row + 1][col] == 1 || map[row][col + 1] == 1))
			continue;

		dfs(nr, nc, i);
	}
	
}

int main() {

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}

	dfs(1,2, WIDTH);

	cout << res;

	return 0;
}