#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 987654321

int V, E;

int main() {
	cin >> V >> E;
	vector<vector<pair<int, int>>> graph(V+1);
	int st;
	cin >> st;

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({v,w});
	}

	// sort(graph.begin(), graph.end());

	vector<int> d(V + 1, INF);
	d[st] = 0;

	priority_queue<pair<int,int>> pq;

	pq.push({ 0,st });  // cost, 시작지점 

	while (!pq.empty())
	{
		int cost = -pq.top().first;  /// 현재 cur 지점까지 오는데 드든 최단 비용(거리)
		int cur = pq.top().second;
		pq.pop();

		for (auto g : graph[cur])
		{
			int next = g.first;
			int nextCost = g.second;

			if (d[next] > cost + nextCost)
			{
				d[next] = cost + nextCost;
				pq.push({ -d[next],next });
			}
		}
		
	}

	for (int i = 1; i <= V; i++)
	{
		if (d[i] == INF)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << d[i] << endl;
		}
	}
	


	return 0; 
}