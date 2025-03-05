#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int t;
int n, k;


int main() {
	cin >> t;

	while (t--) {
		cin >> n >> k;

		vector<int> buildingCost(n + 1);
		vector<vector<int>> graph(n + 1);
		vector<int> degree(n + 1);
		vector<int> dp(n + 1);
		int goal;

		for (int i = 1; i <= n; i++) {
			cin >> buildingCost[i];
		}

		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			graph[x].push_back(y);
			degree[y]++;
		}

		cin >> goal;

		queue<int> q;

		for (int i = 1; i <= n; i++) {
			if (degree[i] == 0) { // degree가 0이라면, queue에 넣어줌. 
								  // 선행 노드가 없는것이다. 즉 시작 노드 
				q.push(i);
				dp[i] = buildingCost[i];
			}
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int g : graph[u]) { // 연결된 노드들 dp값 갱신. 
									 // dp[u]는 노드 u까지 건물을 짓는 데 걸리는 최소 시간. 
				if (dp[g] < dp[u] + buildingCost[g]) {  // 후행노드 기준으로 전행 노드의 최대 시간으로 값을 갱신한다.
					dp[g] = dp[u] + buildingCost[g];
				}
				degree[g]--;
				if (degree[g] == 0) {  // g번째 노드에 선행노드가 없다면 
					q.push(g);
				}
			}
		}

		cout << dp[goal] << endl;
	}

	return 0;
}