#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int w, h;

const int MAX = 50 + 1;

int dx[8] = { 0,0,-1,1,1,1,-1,-1 };
int dy[8] = { -1,1,0,0,1,-1,1,-1 };

bool visited[MAX][MAX] = { false, };
int map[MAX][MAX] = { 0, };

int cnt = 0;
// 0 is ground
// 1 is ocean 

void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= w || ny >= h)
			continue;
		if (!visited[nx][ny] && map[nx][ny])
		{
			visited[nx][ny] = true;
			dfs(nx, ny);
		}
	}
}

int main() {
	
	while (true) { // test case
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (!visited[i][j] && map[i][j]) {
					visited[i][j] = true;
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		cnt = 0;
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}