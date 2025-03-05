#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10001

int v, e;
int parent[MAX];
int ans = 0;

vector<pair<int, pair<int, int>>> graph;

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

int main() {

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		graph.push_back({ cost, { x, y }});
	}

	sort(graph.begin(), graph.end());

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	// 두 노드가 연결돼어 있다면 

	for (int i = 0; i < e; i++) {
		if (SameParent(graph[i].second.first, graph[i].second.second) == false) {
			Union(graph[i].second.first, graph[i].second.second);
			ans += graph[i].first;
		}
	}

	cout << ans;


	return 0;
}