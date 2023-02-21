#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int bfs(char start, char end, vector<string>& maps) {
	int x, y;
	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[0].size(); j++) {
			if (maps[i][j] == start) {
				x = i;
				y = j;
			}
		}
	}
	int check[100][100] = { 0, };
	queue<tuple<int, int, int>> q;
	q.push({ x,y,0 });

	while (!q.empty()) {
		int cnt; 
		tie(x, y, cnt) = q.front();
		q.pop();
		if (maps[x][y] == end) return cnt;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < maps.size() && ny < maps[0].size() 
				&& check[nx][ny] == 0 && maps[nx][ny] != 'X') {
				q.push({ nx,ny,cnt + 1 });
				check[nx][ny] = 1;
			}
		}
	}
	return -1;
}

int solution(vector<string> maps) {
	int answer = 0;
	int a = bfs('S', 'L', maps);
	int b = bfs('L', 'E', maps);
	if (a == -1 || b == -1)
		return -1;
	answer = a + b;
	return answer;
}