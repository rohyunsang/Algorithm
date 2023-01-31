#include <iostream>
#include <queue>

using namespace std;

int n, m, h;
int v[100 + 1][100 + 1][100 + 1];
queue<pair<pair<int, int>, int >> q;

int dx[] = { 0,0,0,0,-1,1 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { -1,1,0,0,0,0 };

void bfs(int n) {
	int cnt = 0;
	while (!q.empty()) {
		cnt++;
		for (int i = 0; i < q.size(); i++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();
			for (int j = 0; j < 6; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				int nz = z + dz[j];

				if (nx >= 0 && ny >= 0 && nz >= 0 &&
					nx < n && ny < n && nz < h) {
					q.push({ {ny,nx},nz });
					v[nz][ny][nx] = 1;
				}
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (v[i][j][k] == 0) {
					cout << -1;
					return;
				}
			}
		}
	}
	cout << cnt - 1;
}

int main() {

	cin >> n >> m >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				int nTmp;
				cin >> nTmp;
				v[i][j][k] = nTmp;
				if (v[i][j][k])
					q.push({ {j,k},i });
			}
		}
	}


	return 0;
}