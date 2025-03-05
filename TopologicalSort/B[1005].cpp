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
			if (degree[i] == 0) { // degree�� 0�̶��, queue�� �־���. 
								  // ���� ��尡 ���°��̴�. �� ���� ��� 
				q.push(i);
				dp[i] = buildingCost[i];
			}
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();

			for (int g : graph[u]) { // ����� ���� dp�� ����. 
									 // dp[u]�� ��� u���� �ǹ��� ���� �� �ɸ��� �ּ� �ð�. 
				if (dp[g] < dp[u] + buildingCost[g]) {  // ������ �������� ���� ����� �ִ� �ð����� ���� �����Ѵ�.
					dp[g] = dp[u] + buildingCost[g];
				}
				degree[g]--;
				if (degree[g] == 0) {  // g��° ��忡 �����尡 ���ٸ� 
					q.push(g);
				}
			}
		}

		cout << dp[goal] << endl;
	}

	return 0;
}