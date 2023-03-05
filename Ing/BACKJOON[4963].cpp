#include <iostream>
#include <string>
#include <vector>

using namespace std;

int w, h;
int cnt = 0;
const int MAX = 51;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[8] = { -1,1,0,0,1,-1,1,-1 };
int dy[8] = { 0,0,-1,1,1,-1,-1,1 };

void InitVisit() {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			visited[i][j] = false;
			map[i][j] = 0;
		}
	}
	cnt = 0;
}

void Input() {
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cin >> map[i][j];
		}
	}
}

void DFS(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= w || ny >= h)
			continue;
		if (visited[nx][ny])
			continue;
		if (map[nx][ny] == 1) {
			DFS(nx, ny);
		}

	}
}

int main() {


	cin >> w >> h;
	Input();
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			if (map[i][j] == 1 && !visited[i][j]) {
				DFS(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	InitVisit();

	return 0;
}