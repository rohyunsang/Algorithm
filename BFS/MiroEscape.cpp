#include <iostream>
#include <queue>
//queue push add last element 
//queue pop delete first element


using namespace std;
//BFS is guaranteed optimal solution
int N, M;
int arr[201][201];

static constexpr int dx[] = { -1,0,1,0 };
static constexpr int dy[] = { 0,-1,0,1 };

/* bool IsSafe(int x, int y)
{
	if ((0 <= x && x < M) && (0 <= y && y <= N))
	{
		return true;
	}
	return false;
}*/

int BFS(int startX, int startY)
{
	queue<pair<int, int>> q;
	q.push({ startX,startY });
	q.pop();

	while (true) {
		cout << "start";
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = x + dy[i];

			if ((nx < 0 || nx >= N || ny < 0 || ny >= M)) continue;
			if (arr[nx][ny] == 0) continue;
			if (arr[nx][ny] == 1) {
				cout << "move";
				arr[nx][ny] = arr[x][y] + 1;
				q.push({ nx,ny });
			}

		}
		if (q.empty()) {
			cout << "finish";
			return arr[N-1][M-1];
		}

	}
}

int main(void)
{
	cin >> N >> M; //(4 <= N, M <= 200);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}
	cout << BFS(0, 0) << endl;


	return 0;
}

// Rules;
// step 1 : go and turn
// recursive ;
