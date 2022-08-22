#include <queue>
#include <iostream>

using namespace std;

int N, M;

queue<pair <int, int>> q;
int graph[1000 + 1][1000 + 1];
 

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs() {
	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = i + dy[i];
			int nx = i + dx[i];
			 

			if (nx >= 0 && ny >= 0 && nx < M && ny < N && graph[ny][nx] == 0)
			{
				graph[ny][nx] = graph[x][y] + 1;
				q.push({ ny,nx });
				
			}
		}

	}

}

int main() {
	int result = -1;
	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 1)
				q.push({ i,j });  // q.push(make_pair(i,j));
		}
	}

	bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (result < graph[i][j]) {
				result = graph[i][j];
			}
		}
	}

	cout << result - 1;

	return 0;
}
