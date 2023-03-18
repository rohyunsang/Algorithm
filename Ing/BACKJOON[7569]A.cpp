#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, h;
const int MAX = 101;
int cnt = 0;
bool visited[MAX][MAX][MAX] = { false, };
int map[MAX][MAX][MAX] = { 0, };

int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };

int answer = 0;

// time -1 => cant
// time 0 => already done
// time n => answer

typedef struct {
	int x, y, z;
	int cnt;
}Point;

queue<Point> q;

int main() {
	cin >> n >> m >> h;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push({ i,j,k,0 });
					visited[i][j][k] = true;
				}
				else if (map[i][j][k] == -1) {
					visited[i][j][k] = true;
				}
			}
		}
	}


	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		cnt = max(cnt, p.cnt);

		for (int i = 0; i < 6; i++) {
			int nx = p.x + dx[i];
			int ny = p.x + dy[i];
			int nz = p.x + dz[i];

			if (nx < 0 || ny < 0 || nz < 0)
				continue;
			if (nx >= n || ny >= m || nz >= h)
				continue;
			q.push({ nx,ny,nz,p.cnt + 1 });
			visited[nx][ny][nz] = true;
		}
	}

	answer = cnt;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (!visited[i][j][k]) {
					answer = -1;
				}
			}
		}
	}

	cout << answer;
	return 0;
}