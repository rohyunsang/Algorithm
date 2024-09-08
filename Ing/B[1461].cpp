#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int hands;
vector<int> v;
vector<bool> isVisited;

bool cmp(int first, int second) {
	return abs(first) < abs(second);
}

int main() {
	int ans = 0;
	queue<pair<int,int>> q;
	
	cin >> n >> hands;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		isVisited.push_back(false);
	}
	

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < 50; i++) {  // prevent out of Range
		v.push_back(0);
		isVisited.push_back(false);
	}

	cout << endl;
	for (auto v : v) {
		cout << " " << v << " ";
	}

	int idx = 0;
	int curHands = 0;
	int cur = v[idx];
	ans += abs(cur);
	q.push({ idx,cur });
	int cost = 0;
	
	cout << endl;
	cout << " ans " << ans << " v[idx] " << v[idx] << endl;
	while (!q.empty()) {
		cur = q.front().second;
		idx = q.front().first;
		q.pop();
		if (v[idx] == 0) continue;

		if (abs(cur - v[idx + 1]) <= abs(cur - v[idx + 2])) {
			if (!isVisited[idx + 1]) {
				q.push({ idx + 2, v[idx + 2] });
				ans += abs(cur - v[idx + 1]);
				if (cost < 0 && v[idx + 1] > 0) curHands = -1;
				if (cost > 0 && v[idx + 1] < 0) curHands = -1;
				cost = v[idx + 1];
				
				cout << " ans " << ans << " v[idx+1] " << v[idx + 1] << endl;
				isVisited[idx + 1] = true;
			}
			else if (!isVisited[idx + 2]) {
				q.push({ idx + 1, v[idx + 1] });
				ans += abs(cur - v[idx + 2]);
				if (cost < 0 && v[idx + 2] > 0) curHands = -1;
				if (cost > 0 && v[idx + 2] < 0) curHands = -1;
				cost = v[idx + 2];
				cout << " ans " << ans << " v[idx+2] " << v[idx + 2] << endl;
				isVisited[idx + 2] = true;
			}
			else {
				continue;
			}
		}
		else {
			if (!isVisited[idx + 2]) {
				q.push({ idx+1, v[idx + 1] });
				ans += abs(cur - v[idx + 2]);
				if (cost < 0 && v[idx + 2] > 0) curHands = -1;
				if (cost > 0 && v[idx + 2] < 0) curHands = -1;
				cost = v[idx + 2];
				cout << " ans " << ans << " v[idx+2] " << v[idx + 2] << endl;
				isVisited[idx + 2] = true;
			}
			else if (!isVisited[idx + 1]) {
				q.push({ idx+2, v[idx + 2] });
				ans += abs(cur - v[idx + 1]);
				if (cost < 0 && v[idx + 1] > 0) curHands = -1;
				if (cost > 0 && v[idx + 1] < 0) curHands = -1;
				cost = v[idx + 1];
				cout << " ans " << ans << " v[idx+1] " << v[idx + 1] << endl;
				isVisited[idx + 1] = true;
			}
			else {
				continue;
			}
		}
		curHands++;
		if (curHands == hands) {
			ans += abs(cost);
			curHands = 0;
		}
	}
	ans -= abs(cost);
	cout << " 정답은 " << ans;


	return 0;
}