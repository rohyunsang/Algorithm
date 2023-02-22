#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
vector<int> e[10001];
bool visit[10001];
vector<pair<int, int>> v;
int n, m;
int hackingCnt = 1;
int maxHacking = 0;

void bfs (int x) {
	visit[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		x = q.front();
		q.pop();

		for (int i = 0; i < e[x].size(); i++) {
			int nx = e[x][i];
			if (!visit[nx])
			{
				visit[nx] = true;
				q.push(nx);
				hackingCnt++;
			}
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		e[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		bfs(i);
		memset(visit, false, sizeof(visit));
		v.push_back({ i,hackingCnt });
		hackingCnt = 1;
	}

	for (const auto& v : v) {
		if (v.second > maxHacking)
			maxHacking = v.second;
	}
	for (const auto& v : v) {
		if (v.second == maxHacking)
			cout << v.first << " ";
	}


	return 0;
}