#include <bits/stdc++.h>

//queue push add last element 
//queue pop delete first element


using namespace std;
//BFS is guaranteed optimal solution
int arr[201][201];
int N, M;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };

/* bool IsSafe(int x, int y)
{
	if ((0 <= x && x < M) && (0 <= y && y <= N))
	{
		return true;
	}
	return false;
}*/

int BFS(int x, int y)
{
	cout << "start";
	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty()) { // queue is empty 
		cout << "start";
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((nx < 0 || nx >= N || ny < 0 || ny >= M)) continue;

			if (arr[nx][ny] == 0) continue;

			if (arr[nx][ny] == 1) {
				cout << "move";
				arr[nx][ny] = arr[x][y] + 1;
				q.push({ nx,ny });
			}

		}
	}
	return arr[N - 1][M - 1];
}

int main(void)
{
	cin >> N >> M; //(4 <= N, M <= 200);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			cout << "for";
		}
	}

	cout << BFS(0, 0) << endl;

	return 0;
}

// Rules;
// step 1 : go and turn
// recursive ;
