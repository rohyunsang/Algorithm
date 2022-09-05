#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // use memset

using namespace std;

int n, m;
int result;
int graph[1001][1001];

struct tomato {
	int y, x;
};
queue<tomato> q; //queue에 좌표를 집어넣고 싶을때 구조체 q를 쓴다.

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs() {

	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (graph[ny][nx] == 0 &&
				0 <= nx && 0 <= ny && nx < m && ny < n) {
				graph[ny][nx] = graph[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}

}

int main() {

	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				q.push({ i,j });
		}
	}

	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
			if (result < graph[i][j]) {
				result = graph[i][j];
			}
		}
	}
	cout << result - 1 << endl;

	return 0;
}