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

// �����̴� ���� ����

// 1 2 4 8 9 
// 1 2 4 1 

// �̺� Ž���� � ������ �̺� Ž���� ���������� �߿��ϴ�.
// ���⿡���� ���� ������ �Ÿ��� �������� �̺� Ž���� �����Ѵ�. 
// �־��� ����(mid)�� �����⸦ ��ġ���� ��, �־��� ������ �����ϴ��� Ȯ���Ѵ�. 
