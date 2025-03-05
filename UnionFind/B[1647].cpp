#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 양 방향 
// 길에 대한 유지비
// MST 

vector<pair<int, pair<int, int>>> graph;
vector<int> parent;

int Find(int x) {
	if (parent[x] != x) {
		parent[x] = Find(parent[x]); 
	}
	return parent[x];
}

void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	parent[y] = x;
	return;
}

bool CompareParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	else return false;
}

int main() {
	int n, m;
	cin >> n >> m;
	int ans = 0;

	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		graph.push_back({ cost,{x,y} });
	}

	parent.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	sort(graph.begin(), graph.end());

	int Tmp = 0;

	for (auto g : graph) {
		int cost = g.first;
		int x = g.second.first;
		int y = g.second.second;
		if (CompareParent(x, y) == false) {
			ans += cost;
			if (cost > Tmp) Tmp = cost;
			Merge(x, y);
		}
	}
	sort(graph.rbegin(), graph.rend());
	ans -= Tmp;

	cout << ans;


	return 0;
}