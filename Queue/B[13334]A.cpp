#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool Comp(pair<int, int> x, pair<int, int> y)
{
	if (x.second == y.second)
		return x.first < y.first;
	return x.second < y.second;
}

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++)
	{
		int st, en;
		cin >> st >> en;
		if (st > en)
		{
			v.push_back({ en,st });
		}
		else
		{
			v.push_back({ st,en });
		}
	}

	sort(v.begin(), v.end(), Comp);

	int l;
	cin >> l;

	// l 
	int ans = 0;
	int cur = 0;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < v.size(); i++)
	{
		// int st = v[i].first;
		// int en = v[i].second;
		int en = v[i].second;
		int st = v[i].second - l;

		while (!pq.empty() && pq.top() < st)
		{
			cur--;
			pq.pop();
		}

		if (v[i].first >= st)
		{
			cur++;
			pq.push(v[i].first);

			ans = max(ans, cur);
		}
	}


	cout << ans;


	return 0; 
}