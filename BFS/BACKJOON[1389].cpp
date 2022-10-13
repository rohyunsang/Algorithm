#include<iostream>
#include<queue>
#include<string.h>  //memset

using namespace std;
int graph[101][101];
bool check[101];

//void bfs();

int main() {
	int n, m;

	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int temp1, temp2;
		cin >> temp1 >> temp2;

		graph[temp1][temp2] = 1;
		graph[temp2][temp1] = 1;
	}

	queue<pair<int, int>> q;

	int sum = 0;
	int result = 214000000;
	int people = 0;

	for (int i = 1; i <= n; i++)
	{
		q.push({ i,0 });  //make_pair
		check[i] = true;
		sum = 0;
		while (!q.empty())
		{

			int curNum = q.front().first;
			int nextLayer = q.front().second + 1;
			q.pop();

			for (int j = 1; j <= n; j++)
			{
				if (graph[curNum][j] == 1 && !check[j])
				{
					check[j] = true;
					q.push({ j, nextLayer });
					sum += nextLayer;
				}
			}
		}

		if (sum < result)
		{
			result = sum;
			people = i;
		}
		memset(check, false, sizeof(check));
	}

	cout << people << endl;
	return 0;
}