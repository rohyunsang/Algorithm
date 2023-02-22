#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> v[1001];
bool visit[1001];

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (visit[next] == 0)
			dfs(next);
	}
}

int main() {
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i])
		{
			dfs(i);
			ans++;
		}
	}

	cout << ans;
}