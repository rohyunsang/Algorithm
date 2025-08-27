#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

#define INF 987654321

int d[126][126];
int graph[126][126];

int main() {
	int n;
	int cnt = 0;

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	do
	{
		cnt++;
		cin >> n;
		if (n == 0) break;
		// vector<pair<int, int>> v(n + 1);
		//vector<vector<int>> d(n + 1);
		//vector<vector<int>> graph(n + 1);


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x;
				cin >> x;
				graph[i][j] = x;
				d[i][j] = INF;
			}
		}

		d[0][0] = graph[0][0];
		priority_queue<pair<int, pair<int, int>>> pq;  // cost, pos X Y 
		pq.push({ -d[0][0], {0,0} });

		while (!pq.empty())
		{
			int cost = -pq.top().first;
			int curX = pq.top().second.first;
			int curY = pq.top().second.second;
			pq.pop();

			for (int i = 0; i < 4; i++)
			{
				int nx = curX + dx[i];
				int ny = curY + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

				int nextCost = graph[nx][ny];

				if (d[nx][ny] > cost + nextCost) 
				{
					d[nx][ny] = cost + nextCost;
					pq.push({ -d[nx][ny], {nx,ny} });
				}
			}
		}


		cout << "Problem " << cnt << ": " << d[n - 1][n - 1] << '\n';

	} while (n != 0);



	return 0; 
}