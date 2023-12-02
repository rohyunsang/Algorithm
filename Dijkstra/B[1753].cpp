#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 20002
#define INF 1987654321

int v, e;
int k; // start point
int d[MAX];
vector<pair<int, int>> Vertex[MAX];
priority_queue<pair<int, int>> pq; // cost, Vertex


int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> v >> e;
	cin >> k; // start point

	for (int i = 0; i < e; i++) {
		int startV, endV, cost;
		cin >> startV >> endV >> cost;
		Vertex[startV].push_back({ endV,cost });
	}
	for (int i = 1; i <= v; i++) {
		d[i] = INF;
	}

	pq.push({ 0,k });
	d[k] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int i = 0; i < Vertex[cur].size(); i++) {
			int next = Vertex[cur][i].first;
			int nextCost = Vertex[cur][i].second;

			if (d[next] > cost + nextCost) {
				d[next] = cost + nextCost;
				pq.push({ -d[next],next });
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}
		

	return 0;
}