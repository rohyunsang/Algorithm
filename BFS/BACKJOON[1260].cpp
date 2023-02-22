#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, v;
vector<int> e[1001];
bool visit[1001];

void dfs(int start) {
	visit[start] = true;
	cout << start << ' ';
	for (int i = 0; i < e[start].size(); i++) {
		int next = e[start][i];
		if (!visit[next])
			dfs(next);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int i = 0; i < e[cur].size(); i++) {
			int next = e[cur][i];
			if (!visit[next])
			{
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) { //edge start 1 
		sort(e[i].begin(), e[i].end());
	}

	dfs(v);
	cout << '\n';
	memset(visit, false, sizeof(visit));
	bfs(v);


	return 0;
}