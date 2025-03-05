#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<pair<int, int>> v;
	priority_queue<int ,vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	pq.push(v[0].second);
	ans++;

	for (int i = 1; i < n; i++) {
		if (pq.top() > v[i].first) { // ���� �Ұ� �� �ϳ� �߰�
			ans++;
			pq.push(v[i].second);
		}
		else { // ���� ����
			pq.pop();
			pq.push(v[i].second);
		}
	}

	cout << ans;

	return 0;
}