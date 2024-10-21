#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//  a -> b evaultion sequence

int main() {
	int n;
	cin >> n;

	vector<vector<int>> g(n + 1);
	vector<int> buildingCost(n + 1);
	vector<int> degree(n + 1);
	vector<int> dp(n + 1);

	

	for (int i = 1; i <= n; i++) {
		cin >> buildingCost[i];
		int nTmp = 0;

		while (true) {

			cin >> nTmp;
			if (nTmp == -1) break;
			g[nTmp].push_back(i);
			degree[i]++;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);  // 시작 노드 . 
			dp[i] = buildingCost[i];
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int next : g[u]) {
			
			//dp[next] = max(dp[next], dp[u] + buildingCost[next]);
			
			if (dp[next] < dp[u] + buildingCost[next]) {
				dp[next] = dp[u] + buildingCost[next];
			}
			degree[next]--;
			if (degree[next] == 0) 
				q.push(next);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dp[i] << '\n';
	}


	return 0;
}