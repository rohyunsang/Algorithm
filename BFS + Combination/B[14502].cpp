#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

int map[8][8];
vector<int> ans;
vector<pair<int, int>> virus;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void SpreadVirus(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
	int copyMap[8][8];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
	copyMap[p1.first][p1.second] = 1;
	copyMap[p2.first][p2.second] = 1;
	copyMap[p3.first][p3.second] = 1;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyMap[i][j] == 2)
				q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (copyMap[nx][ny] == 2) continue;
			if (copyMap[nx][ny] == 1) continue;
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (copyMap[nx][ny] == 0) {
				copyMap[nx][ny] = 2;
				q.push({ nx,ny });
			}

		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyMap[i][j] == 0) cnt++;
		}
	}
	ans.push_back(cnt);
}


int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				virus.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < virus.size(); i++) {
		for (int j = i + 1; j < virus.size(); j++) {
			for (int k = j + 1; k < virus.size(); k++) {
				SpreadVirus(virus[i], virus[j], virus[k]);
			}
		}
	}

	int answer = *max_element(ans.begin(), ans.end());
	cout << answer;

	return 0;
}