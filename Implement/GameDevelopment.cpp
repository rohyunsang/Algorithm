#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace chrono;

int arr[50][50]; //ocean
int flag[50][50]; //visited

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };  

int result = 0;
int turnCnt = 0;
int direction;

void TurnLeft() {
	direction = direction - 1;
	if (direction == -1) {
		direction = 3;
	}
	//3 2 1 0 
}

void Moving(int x, int y, int direction) {
	cout << "a";
	flag[x][y] = 1;
	TurnLeft();
	int nx = x + dx[direction];
	int ny = y + dy[direction];
	if (arr[nx][ny] == 0 && flag[nx][ny] == 0) //if go forward
	{
		cout << "b";
		flag[nx][ny] = 1;
		x = nx;
		y = ny;
		result++;
		turnCnt = 0;
	}
	else {
		turnCnt++;
		cout << "c";
	}//if cant forward

	if (turnCnt == 4) {//cant move 
		cout << "d";
		nx = x - dx[direction];
		ny = y - dy[direction];

		if (arr[nx][ny] == 0) { //if !ocean
			x = nx;
			y = ny;
			cout << "e";
		}
		else return; //if ocean return ;

		turnCnt = 0;
	}
	cout << "f";
	Moving(x, y, direction);
}


int main() {
	auto startTime = std::chrono::system_clock::now();

	int N, M; //(3 <= N, M <= 50)
	cin >> N >> M;

	int x;
	int y;

	cin >> x >> y >> direction;

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

	Moving(x, y, direction);
	cout << result << endl;
	auto endTime = std::chrono::system_clock::now();
	auto sec = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

	cout << sec.count();
	return 0;
}