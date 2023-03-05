#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 101;

int n;
string sTmp;
// R equal G 

char map[MAX][MAX];
bool visited[MAX][MAX]; 

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int bfs(int startX, int startY) {
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	visited[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (visited[nx][ny])
				continue;
			if (map[x][y] != map[nx][ny])
				continue;

			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}
	return 1;
}

int main() {
	cin >> n;
	vector<int> normal;
	vector<int> colorWeakness;

	for (int i = 0; i < n; i++) {
		cin >> sTmp;
		for (int j = 0; j < sTmp.size(); j++) {
			map[i][j] = sTmp[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(!visited[i][j])
				normal.push_back(bfs(i, j));
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G')
				map[i][j] == 'R';
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j])
				colorWeakness.push_back(bfs(i, j));
		}
	}

	cout << normal.size() << " " << colorWeakness.size();
	
	return 0;
}