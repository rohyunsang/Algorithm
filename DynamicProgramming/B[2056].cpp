#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> costs;
vector<int> degrees;
vector<int> dp;
vector<vector<int>> graph;
// vector<bool> visited;

int main()
{
	int n;
	cin >> n;
	
	costs.resize(n + 1);
	degrees.resize(n + 1);
	dp.resize(n + 1);
	graph.resize(n + 1);
	// visited.resize(n + 1, false);

	for (int i = 1; i <= n; i++)
	{
		int cost;
		int childs;
		cin >> cost >> childs;
		costs[i] = cost;

		for (int j = 0; j < childs; j++)
		{
			degrees[i]++;
			int child;
			cin >> child;
			graph[child].push_back(i);
		}
	}

	queue<int> q;
	
	for (int i = 1; i <= n; i++)
	{
		if (degrees[i] == 0)
		{
			q.push(i);
			dp[i] = costs[i];
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto parent : graph[cur])
		{
			if (dp[parent] < dp[cur] + costs[parent])
			{
				dp[parent] = dp[cur] + costs[parent];
			}
			degrees[parent]--;
			if (degrees[parent] == 0)
			{
				q.push(parent);
			}
		}
	}

	// 무조건 마지막 번호가 마지막 작업
	// -> 근데 이거는 dp에 적용 안됨 

	int ans = 0;
	for (int k = 1; k <= n; k++)
	{
		if (ans < dp[k]) ans = dp[k];
	}
	cout << ans ;


	return 0; 
}