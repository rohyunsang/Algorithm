#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int v;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int cur) {
	cout << cur << " ";
	visited[cur] = true;
	for (auto g : graph[cur])
	{
		int next = g;
		if (visited[next] == false)
		{
			dfs(g);
		}
	}
}

int main() {
	cin >> n >> m >> v;
	visited.resize(n + 1);
	graph.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;
		graph[st].push_back(en);
		graph[en].push_back(st);
	}
	
	for (int i = 1; i <= n; ++i) sort(graph[i].begin(), graph[i].end());

	dfs(v);

	return 0;
}