#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 10001

int n, k;
int parent[MAX];
int ans1 = 0;
int ans2 = 0;

bool visited[MAX] = { false };
int endPoint = 0;

vector<pair<int, pair<int, int>>> graph;
vector<pair<int, int>> graph2[MAX];

int Find(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) parent[y] = x;
}

bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	else return false;
}


void DFS(int cur, int dist) {
	if (visited[cur]) return;

	visited[cur] = true;
	if (ans2 < dist) {
		ans2 = dist;
		endPoint = cur;
	}
	for (int i = 0; i < graph2[cur].size(); i++) {
		DFS(graph2[cur][i].first, dist + graph2[cur][i].second);
	}
}

int main() {

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		graph.push_back({ cost, { x, y } });
	}

	sort(graph.begin(), graph.end());

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	// 두 노드가 연결돼어 있다면 

	for (int i = 0; i < k; i++) {
		int u = graph[i].second.first;
		int v = graph[i].second.second;
		int cost = graph[i].first;


		if (SameParent(u, v) == false) {
			Union(u, v);
			ans1 += cost;

			graph2[u].push_back({ v,cost });
			graph2[v].push_back({ u,cost });
		}
	}

	cout << ans1 << endl;

	DFS(0, 0);

	ans2 = 0;
	memset(visited, false, sizeof(visited));

	DFS(endPoint, 0);
	cout << ans2;


	return 0;
}