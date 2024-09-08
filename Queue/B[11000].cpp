#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 5 9 
// 1 10
// 


int main() {
	int n;
	cin >> n;
	int ans = 0;

	vector<pair<int,int>> v;
	// endTime, startTime;
	for (int i = 0; i < n; i++) {
		int startTime, endTime;
		cin >> startTime >> endTime;

		v.push_back({ startTime, endTime });
	}

	sort(v.begin(), v.end());

	int endTime = 0;
	priority_queue<int, vector<int>, greater<int>> pqEndTime;
		
	ans++;
	queue<pair<int, int>> pq;

	for (int i = 0; i < v.size(); i++) {
		pq.push({ v[i].first, v[i].second });
		//cout << v[i].first << " " << v[i].second;
		//cout << endl;
	}

	pqEndTime.push(pq.front().second);
	pq.pop();

	while (!pq.empty()) {
		if(pqEndTime.top() <= pq.front().first) {
			pqEndTime.pop();
			pqEndTime.push(pq.front().second);
			
			pq.pop();
			if (!pqEndTime.empty() && !pq.empty()) {
				if (pqEndTime.top() <= pq.front().second) {
					continue;
				}
			}
			
		}
		else {
			pqEndTime.push(pq.front().second);
			pq.pop();
			ans++;
		}
			
	}

	cout << ans;

	return 0;
}