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
		if (curEnd <= v[i].second)  // �� ȸ�� ���� ����, �� ȸ�� ���� �ð��� ũ�ų� ���ٸ� ���� .
		{
			ans++;
			curEnd = v[i].first; // ����.
		}
	}

	cout << ans;






	return 0; 
}