#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS

bool isVisit[101];
int map[101];

queue<pair<int,int>> q;

void bfs(int _start, int _cnt) {
	q.push({ _start, _cnt });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nx = x + i;
			if (nx == 100) {
				cout << cnt + 1;
				return;
			}
			else if (nx < 100) {
				while (map[nx] != 0) {
					nx = map[nx];
				}
				if (!isVisit[nx]) {
					q.push({ nx,cnt + 1 });
					isVisit[nx] = true;
				}
			}
		}


	}
}

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		
		int x, y;
		cin >> x >> y;
		map[x] = y;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		map[x] = y;
	}

	bfs(1,0);


	return 0;
}