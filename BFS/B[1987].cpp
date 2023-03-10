#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int r, c;
vector<string> v;
vector<char> db;
bool visited[20][20];
queue<pair<int, int>> q;

int cnt = 1;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool flag = true;

// start at 0,0 
// db bfs? 

void dfs() {
	int startX = 0;
	int startY = 0;
	db.push_back(v[startX][startY]);

	q.push({ startX, startY });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!visited[nx][ny])
				continue;
			if (nx < 0 || ny < 0 || nx >= r || ny >= c)
				continue;
			for (int i = 0; i < db.size(); i++) {
				if (db[i] == v[nx][ny])
				{
					flag = false;
					break;
				}
			}
			if (!flag) {
				flag = true;
				continue;
			}
			q.push({ nx,ny });
			visited[nx][ny] = true;
			db.push_back(v[nx][ny]);
			cnt++;
		}
	}
}


int main() {
	cin >> r;
	while (r--) {
		string sTmp;
		cin >> sTmp;
		v.push_back(sTmp);
	}

	dfs();

	cout << cnt;

	return 0;
}