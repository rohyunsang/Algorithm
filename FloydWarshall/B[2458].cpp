#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int graph[501][501];

#define INF 987654321

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			graph[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;
		graph[st][en] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1 ; k <= n; k++)
			{
				if(graph[j][k] > graph[j][i] + graph[i][k])
					graph[j][k] = graph[j][i] + graph[i][k];
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n ; j++)
		{
			if (graph[i][j] != INF || graph[j][i] != INF)
				cnt++;
		}
		if (cnt == n - 1)ans++;
	}

	cout << ans;

	return 0; 
}


// 다 연결돼있으면 키 순서 정확히 파악 가능.