#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
string sTmp;
int cnt = 0;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

const int MAX = 101;
char map[MAX][MAX];
bool visited[MAX][MAX] = { false, };

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n)
			continue;
		if (visited[nx][ny])
			continue;
		if (map[x][y] == map[nx][ny])
			dfs(nx, ny);
	}
}



int main() {
	cin >> n;

	//input
	for (int i = 0; i < n; i++) {
		cin >> sTmp;
		for (int j = 0; j < n; j++) {
			map[i][j] = sTmp[j];
		}
	}
	//dfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << " ";
	
	//init
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	//normal to colorWeakness
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') map[i][j] = 'R';
		}
	}

	//again dfs
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j])
			{
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;

	return 0;
}