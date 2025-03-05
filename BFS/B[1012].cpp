#include <iostream>
#include <queue>

using namespace std;

int map[51][51];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int n, m, k;
int ans;

void bfs(int i, int j) {
	
	queue<pair<int, int >> q;
	q.push({ i,j });
	map[i][j] = 0;
	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 1) {
				q.push({ nx,ny });
				map[nx][ny] = 0;
			}
		}
	}
}

int main() {


	int t;
	cin >> t;
	while (t--) {

		ans = 0; // init
		
		cin >> n >> m >> k;

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					bfs(i, j);
					ans++;
				}
			}
		//	cout << endl;
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << map[i][j] << " ";
			}
			cout << endl;
		}
		*/
		cout << ans << endl;

		// init
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = 0;
			}
		}
	}

	


	return 0;
}