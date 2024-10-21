#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n+1);
	vector<int> depth(n+1);
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		depth[y]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (depth[i] == 0) 
		{
			pq.push(i);
		}
	}


	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();

		cout << cur << " ";

		for (int next : graph[cur]) {
			depth[next]--;
			if (depth[next] == 0) {
				pq.push(next);
			}
		}
	}


	return 0; 
}