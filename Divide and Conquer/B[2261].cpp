#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 987654321;

vector<pair<int, int>> v;

int dist(const pair<int, int>& x, const pair<int, int>& y)
{
	int dx = x.first - y.first;
	int dy = x.second - y.second;

	return dx * dx + dy * dy;
}

bool comp(const pair<int, int>& x, const pair<int, int>& y)
{
	return x.second < y.second;
}

void DivConq(int st, int en)
{
	if (en - st <= 1) return; // none or zero 

	int mid = (st + en) / 2;
	int midX = v[mid].first;


	DivConq(st, mid);
	DivConq(mid, en);

	vector<pair<int, int>> strip;


	// strip candiates
	for (int i = st; i < en; i++)
	{
		int dx = v[i].first - midX;
		if (dx * dx < ans)
			strip.push_back(v[i]);
	}

	sort(strip.begin(), strip.end(), comp);

	int stripSize = (int)strip.size();

	for (int i = 0; i < stripSize; i++)
	{
		for (int j = i + 1; j < stripSize; j++)
		{
			int dy = strip[j].second - strip[i].second;
			if (dy * dy >= ans) break;

			ans = min(ans, dist(strip[i], strip[j]));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;


	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}

	sort(v.begin(), v.end());

	DivConq(0, n);

	cout << ans;

	return 0;
}


// strip 
// https://devrepo.tistory.com/58