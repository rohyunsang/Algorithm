#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;

const int MAX = 100 + 1;

int cnt = -1;

char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<int> soldiers;
vector<int> enemy;
queue<pair<int, int>> q;

int bfs(int startX, int startY) {
	q.push({ startX,startY });
	visited[startX][startY] = true;


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visited[nx][ny])
				continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] != map[x][y])
				continue;
			q.push({ nx,ny });
			visited[nx][ny] = true;
			
		}
		cnt++;
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'W' && !visited[i][j])
			{
				soldiers.push_back(bfs(i, j));
				cnt = 0;
			}
			else if (map[i][j] == 'B' && !visited[i][j]) {
				soldiers.push_back(bfs(i, j));
				cnt = 0;
			}
		}
	}

	sort(soldiers.begin(), soldiers.end());
	sort(enemy.begin(), enemy.end());
	
	for (const auto s : soldiers)
		cout << s << " ";
	cout << endl;
	
	for (const auto e : enemy)
		cout << e << " ";

	return 0;
}