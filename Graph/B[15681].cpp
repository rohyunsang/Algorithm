#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<int> dp;
vector<bool> visited;

int dfs(int node) {
	if (visited[node] == true) return dp[node];
	visited[node] = true;

	for (auto next : v[node]) {
		if (visited[next] == true) continue;
		dp[node] = dp[node] + dfs(next);
	}
	
	return dp[node];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	int r;
	int q;
	cin >> n >> r >> q;

	v.resize(n + 1);
	dp.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
	}

	dfs(r);

	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		cout << dp[x] << '\n';
	}



	return 0;
}