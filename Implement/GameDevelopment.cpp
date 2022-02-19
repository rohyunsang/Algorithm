#include <bits/stdc++.h>

using namespace std;

int arr[50][50]; //ocean
int flag[50][50]; //visited

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int result = 1;
int turnCnt = 0;
int dir;

void Moving(int x, int y, int dir) {
	
	flag[x][y] = 1;
	dir = dir - 1;
	if (dir == -1)
	{
		dir = 3;
	}
	
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (arr[nx][ny] == 0 && flag[nx][ny] == 0) //if go forward
	{
		
		flag[nx][ny] = 1;
		x = nx;
		y = ny;
		result++;
		turnCnt = 0;
	}
	else {
		turnCnt++;
		
	}//if cant forward

	if (turnCnt == 4) {//cant move 
		
		nx = x - dx[dir];
		ny = y - dy[dir];

		if (arr[nx][ny] == 0) { //if !ocean
			x = nx;
			y = ny;
			
		}
		else return; //if ocean return ;

		turnCnt = 0;
	}
	
	Moving(x, y, dir);
}


int main() {


	int N, M; //(3 <= N, M <= 50)
	cin >> N >> M;

	int x;
	int y;

	cin >> x >> y >> dir;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int x;
			cin >> x;
			arr[i][j] = x;
			flag[i][j] = 0;
		}
	}

	Moving(x, y, dir);
	cout << result << endl;

	return 0;
}