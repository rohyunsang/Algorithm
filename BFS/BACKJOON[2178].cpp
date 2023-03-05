#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAX = 101;
int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };
int n, m;
int cnt = 1;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
string s;


void bfs(int startX,int startY) {
	queue<pair<pair<int, int>, int>> q;
	q.push({{ startX,startY },cnt});

	while (!q.empty()) {

		int x = q.front().first.first;
		int y = q.front().first.second;
		cnt = q.front().second;
		cnt++;
		q.pop();		

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] == 0)
				continue;
			if (map[nx][ny] == 1) {
				q.push({ { nx,ny },cnt });
				visited[nx][ny] = true;
				map[nx][ny] = cnt;
			}
			
		}
	}
}

int main() {
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j] - '0';
		}
	}

	bfs(0, 0);

	cout << map[n - 1][m - 1];

	return 0;
}

// 문제를 잘 읽자 