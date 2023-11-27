#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m; //  1 <= n, m <= 600

bool isVisit[600][600];
char map[600][600];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> q;

int BFS(int start_x, int start_y) {
	q.push({ start_x,start_y });
	int res = 0;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		isVisit[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (isVisit[nx][ny]) continue;
			if (map[nx][ny] == 'X') continue;
			if (map[nx][ny] == 'P') res++;
			q.push({ nx,ny });
		}

	}

	return res;
}

int main() {
	cin >> n >> m;
	int x = -1;
	int y = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char cTmp;
			cin >> cTmp;
			map[i][j] = cTmp;
			if (cTmp == 'I') {
				x = i;
				y = j;
			}
		}
	}

	int res = BFS(x, y);
	if (res == 0) {
		cout << "TT" << endl;
	}
	else {
		cout << res;
	}
	


	return 0;
}