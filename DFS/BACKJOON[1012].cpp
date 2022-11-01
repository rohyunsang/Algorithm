#include <iostream>
#include <algorithm>
#include <string.h> // or memory.h

using namespace std;

int t;

int graph[51][51];
bool visit[51][51];
int n, m, k;
int cnt = 0;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };


void dfs(int x, int y) {

	visit[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		else if (graph[nx][ny] == 1 && !visit[nx][ny]) {
			dfs(ny, nx);
		}
	}
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++) {
			int xTmp, yTmp;
			cin >> xTmp >> yTmp;
			graph[yTmp][xTmp] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (graph[i][j] == 1 && !visit[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
		memset(visit, false, sizeof(visit));
		memset(graph, 0, sizeof(graph));
		cnt = 0;
	}

	return 0;
}