#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> buildingCost(n + 1);
		vector<vector<int>> graph(n + 1);
		vector<int> degree(n + 1);
		vector<int> dp(n + 1);
		int goal;

		for (int i = 1; i <= n; i++) { // cost
			cin >> buildingCost[i];
		}

		for (int i = 0; i < k; i++) { // mapping graph
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			degree[y]++; // connected node count
		}

		cin >> goal;

		queue<int> q;
		
		for (int i = 1; i <= n; i++) {
			if (degree[i] == 0) { // 선행 노드가 없다면 
				q.push(i);
				dp[i] = buildingCost[i];
			}
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int g : graph[u]) {
				if (dp[g] < dp[u] + buildingCost[g]) {
					dp[g] = dp[u] + buildingCost[g];
				}
				degree[g]--;
				if (degree[g] == 0) {
					q.push(g);
				}
			}
		}
		
		cout << dp[goal] << endl;
		

	}



	return 0;
}


// https://www.acmicpc.net/problem/1005