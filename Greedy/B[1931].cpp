#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	// sort
	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;


		v.push_back({ en,st });
	}

	sort(v.begin(), v.end());

	int ans = 0;
	int curEnd = -1;

	for (int i = 0; i < n; i++)
	{
		if (curEnd <= v[i].second)  // 앞 회의 끝난 이후, 뒷 회의 시작 시간이 크거나 같다면 가능 .
		{
			ans++;
			curEnd = v[i].first; // 갱신.
		}
	}

	cout << ans;






	return 0; 
}