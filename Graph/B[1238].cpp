#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 2123456789
int n, m, endPoint;


void Search(int startPoint, vector<vector<pair<int,int>>> &v, vector<int> &dp) {
	dp[startPoint] = 0;

	queue<pair<int,int>> q;

	q.push({ startPoint, dp[startPoint]});

	while (!q.empty()) {
		int cur = q.front().first;
		int cost = q.front().second;

		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int nextCity = v[cur][i].first;
			int moveCost = v[cur][i].second;

			if (dp[nextCity] > dp[cur] + moveCost) {
				dp[nextCity] = dp[cur] + moveCost;
				// cout << "Debug " << dp[nextCity] << " " << dp[cur] << " " << moveCost << " " << endl;
				q.push({ nextCity, 0 });
			}
			
		}
	}
}

void Init(vector<int>& dp){
	for (int i = 1; i <= m; i++) {
		dp[i] = INF;
	}
}

int main() {
	int maxNum = -2123456789;
	
	cin >> n >> m >> endPoint;
	vector<vector<pair<int,int>>> v(m + 1);
	vector<int> dp(m + 1);

	for (int i = 0; i < m; i++) {
		int x, y, cost;
		cin >> x >> y >> cost;
		v[x].push_back({ y,cost });
	}

	for (int i = 1; i <= n; i++) {
		Init(dp);
		Search(i, v, dp);
		int _go = dp[endPoint];
		Init(dp);
		Search(endPoint, v, dp);
		int _back = dp[i];
		maxNum = max(maxNum, _go + _back);
		//cout << "maxNum is " << maxNum << endl;
	}

	cout << maxNum;

	return 0;
}



//