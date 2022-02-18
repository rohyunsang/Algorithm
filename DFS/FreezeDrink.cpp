#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[1001][1001];

bool dfs(int x, int y) {
	if (x <= -1 || x >= N || y <= -1 || y >= M)
	{
		return false;
	}

	if (arr[x][y] == 0)
	{
		arr[x][y] = 1;
		dfs(x - 1, y);
		dfs(x + 1, y);
		dfs(x, y - 1);
		dfs(x, y + 1);
		return true;
	}
	return false;
}

int main(void)
{
	int result = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (dfs(i, j) == true)
			{
				result++;
			}
		}
	}

	cout << result;

	return 0;
}

/*00110
  00011
  11111
  00000*/  // 0 is empty 
  // i is wall 

// step 1 up
// step 2 left
// step 3 down
// step 4 right

// if out of array => wall , perceive as a wall

// ¡Ú visited 