#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> v;
	
	for (int i = 0; i < n; i++)
	{
		int w, cost;
		cin >> w >> cost;

		v.push_back({ w,cost });
	}

	sort(v.begin(), v.end());

	vector<int> d(k + 1, 0);

	for (auto v : v)
	{
		int w = v.first;
		int cost = v.second;

		for (int cur = k; cur >= w; cur--)  //  같은 물건을 한번만쓰기 위해 역순 
		{
			d[cur] = max(d[cur], d[cur - w] + cost);
		}
	}

	// first 3, 6
	// d[7] 
	/*
	for (auto d : d)
	{
		cout << d << " ";
	}

	*/

	cout << d[k];

	/*
	for (int cur = k - 1; v[cur].second <  ; cur--)
	{
		d[7] = max(dp[7], dp[k-cur] + v[cur].second)
	}
	*/


	return 0; 
}