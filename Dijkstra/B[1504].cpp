#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define INF 2123456789
int n, e;
void Search(int start, vector<vector<pair<int,int>>> &node, vector<int> &dp) {
	
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
	}

	dp[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });


	while (!pq.empty()) {
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[cur].size(); i++) {
			int next = node[cur][i].first;
			int nCost = node[cur][i].second;

			if (dp[next] > cost + nCost) {
				dp[next] = cost + nCost;
				pq.push({ -dp[next],next });
			}
		}
	}
}

int main() {

	cin >> n >> e;
	
	vector<vector<pair<int,int>>> node(n+1);
	vector<int> dp(n + 1);

	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
	}

	for (int i = 0; i < e; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		node[x].push_back({ y,z });
		node[y].push_back({ x,z });
	}

	int midPoint1, midPoint2;
	cin >> midPoint1 >> midPoint2;

	int sToMid1;
	int sToMid2;
	int mid1ToMid2;  // mid1->mid2 == mid2->mid1
	int Mid1ToGoal;
	int Mid2ToGaal;

	// 1 -> midPoint1, 1 -> midPoint2
	int path1 = 0;
	Search(1, node, dp);
	sToMid1 = dp[midPoint1];
	sToMid2 = dp[midPoint2];

	// 2 midpoint1 -> midpoint2, midpoint1 -> goal
	Search(midPoint1, node, dp);
	mid1ToMid2 = dp[midPoint2];
	Mid1ToGoal = dp[n];


	// 3 midpoint2 -> goal 
	Search(midPoint2, node, dp);
	Mid2ToGaal = dp[n];

	int ans = INF;
	bool flagA = true;
	bool flagB = true;
	
	if (sToMid1 == INF || mid1ToMid2 == INF || Mid2ToGaal == INF)
		flagA = false;
	else
		ans = min(ans, sToMid1 + mid1ToMid2 + Mid2ToGaal);

	if (sToMid2 == INF || mid1ToMid2 == INF || Mid1ToGoal == INF)
		flagB = false;
	else
		ans = min(ans, sToMid2 + mid1ToMid2 + Mid1ToGoal);

	if (!flagA && !flagB)
		cout << -1;
	else
		cout << ans;

	return 0;
}


// 1 -> midPoint1 -> midPoint2 -> end;
// 1 -> midPoint2 -> midPoint1 -> end;
