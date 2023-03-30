#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 1987654321

int v, e;
int k; // start node;
vector<pair<int,int>> node[20000 + 1];
int dist[20000 + 1];
int u, V, w;
priority_queue<pair<int, int>> q;

int main() {

	cin >> v >> e;
	cin >> k;
	while (e--) { //mapping
		cin >> u >> V >> w;
		node[u].push_back({ V,w });
		// v[1].(4,3) // 1 to 4 cost 3 
	}
	q.push({ 0,k });
	dist[k] = 0;
	while (!q.empty())
	{
		int cost = -q.top().first;
		int cur = q.top().second;
		q.pop();

		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i].first;
			int nextCost = node[cur][i].second;

			if (dist[next] > cost + nextCost) {
				dist[next] = cost + nextCost;
				q.push({ -dist[next],next });
			}
		}
	}
	
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}


	return 0;
}