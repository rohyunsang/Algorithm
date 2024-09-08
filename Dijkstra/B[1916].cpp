#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int m;

#define INF 2123456789

void Bus(int startPoint, int endPoint, vector<vector<pair<int, int>>> &v, vector<int> &dp) {
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	dp[startPoint] = 0;
	pq.push({ 0, startPoint });

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		
		pq.pop();

		if (dp[cur] < cost)
			continue;

		for (int i = 0; i < v[cur].size(); i++) {
			int nextCity = v[cur][i].first;
			int nextCost = v[cur][i].second + cost;
			

			if (dp[nextCity] > nextCost) {
				dp[nextCity] = nextCost;
				pq.push({ nextCost, nextCity });

			}
		}
	}
}

int main() {
	cin >> n;
	cin >> m;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<vector<pair<int, int>>> v(n + 1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
	}

	for (int i = 1; i <= m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back({ y, cost });
	}

	int startPoint = 0;
	int endPoint = 0;

	cin >> startPoint >> endPoint;

	Bus(startPoint, endPoint, v, dp);

	cout << dp[endPoint];

	return 0;
}