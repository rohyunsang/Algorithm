#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, start;

vector<pair<int, int>> graph[30001];
int d[30001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	// 시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입.

	pq.push({ 0,start });
	d[start] = 0;
	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push(make_pair(-cost, graph[now][i].first));
			}
		}
	}
}

int main(void) {

	cin >> n >> m >> start;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({ y,z });
	}

	fill(d, d + 30001, INF);

	dijkstra(start);

	int count;
	int maxDistance = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) {
			count += 1;
			maxDistance = max(maxDistance, d[i]);
		}
	}

	cout << count - 1 << ' ' << maxDistance << '\n';

	return 0;
}

