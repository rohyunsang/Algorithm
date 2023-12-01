#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// state width 
// move (1,0) (1,1)

// state height
// move (0,1) (1,1)

// state cross
// move (1,0) (0,1) (1,1)

// width is 0,
// height is 1,
// cross is 2

int n;
int map[17][17];

int dx[3] = { 0,1,1 };
int dy[3] = { 1,0,1 };

int res = 0;

void DFS(int r, int c, int state) {
	if (r == n - 1 && c == n - 1) {
		res++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (state == 0 && i == 1) continue;
		if (state == 1 && i == 0) continue;

		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
		if (map[nr][nc] == 1) continue;
		if (i == 2 && (map[r + 1][c] == 1 || map[r][c + 1] == 1)) continue;
		DFS(nr,nc,i);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	DFS(0,1,0);

	cout << res;

	return 0;
}