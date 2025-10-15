#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

// 친구와 연결된 친구꺼까지 뺏기. 
// K명 뺏기 -> 안됨
// K - 1 명까지. 

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	// child, edge cnt, max 

	vector<pair<int, int>> d;

	vector<vector<int>> graph(n + 1);
	unordered_map<int, int> um;
	for (int i = 1; i <= n; i++)
	{
		int candy;
		cin >> candy;
		um[i] = candy;
	}

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;

		graph[st].push_back(en);
		graph[en].push_back(st);
	}

	vector<bool> visited(n + 1);

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == true) continue;
		queue<int> q;
		q.push(i);
		visited[i] = true;

		int childCnt = 0;
		int candyCnt = 0;

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			childCnt++;
			candyCnt += um[cur];

			for (auto next : graph[cur])
			{
				if (visited[next] == false)
				{
					q.push(next);
					visited[next] = true;
					
				}
			}
		}

		d.push_back({ childCnt, candyCnt });
	}

	// 노드 집합간의 최대값. 
	/**
	for (auto d : d)
	{
		cout << d.first << " " << d.second << " ";
	}
	*/
	sort(d.begin(), d.end());

	int CAP = k > 0 ? k - 1 : 0;

	// dp[w] = 인원수 w로 얻을 수 있는 최대 캔디
	vector<int> dp(CAP + 1, 0);

	for (auto& it : d)
	{
		int w = it.first;
		int val = it.second;
		for (int cur = CAP; cur >= w; --cur)
		{
			dp[cur] = max(dp[cur], dp[cur - w] + val);
		}
	}

	cout << dp[CAP] << '\n';

	return 0; 
}