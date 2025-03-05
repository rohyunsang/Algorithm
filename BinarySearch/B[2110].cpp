#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, c;
	cin >> n >> c;

	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int start = 1;
	int end = v.back() - v.front();
	int ans = 0;

	while (start <= end) {
		int mid = (start + end) / 2;
		int cnt = 1;
		int prev = v[0];

		for (int i = 1; i < n; i++) {
			if (v[i] - prev >= mid) {
				cnt++;
				prev = v[i];
			}
		}

		if (cnt >= c) {
			ans = max(ans, mid);
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans;
	
	return 0;
}

// 도현이는 집이 많네

// 1 2 4 8 9 
// 1 2 4 1 

// 이분 탐색은 어떤 것으로 이분 탐색을 진행할지가 중요하다.
// 여기에서는 집들 사이의 거리를 기준으로 이분 탐색을 진행한다. 
// 주어진 간격(mid)로 공유기를 설치했을 때, 주어진 조건을 충족하는지 확인한다. 
