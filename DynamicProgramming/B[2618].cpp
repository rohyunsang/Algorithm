#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, w;
vector<pair<int, int>> incident;
int dp[1002][1002][2];

int dist(int a, int b) 
{
	return abs(incident[a].first - incident[b].first) + abs(incident[a].second - incident[b].second);
}

int MoveCap(int cur, int cap1, int cap2)
{
	if (cur >= w + 2) return 0;

	int &ret = dp[cap1][cap2][0];
	if (ret != -1) return ret;

	int cap1_distance = dist(cur, cap1) + MoveCap(cur + 1, cur, cap2);
	int cap2_distance = dist(cur, cap2) + MoveCap(cur + 1, cap1, cur);

	if (cap1_distance < cap2_distance)
	{
		ret = cap1_distance;
		dp[cap1][cap2][1] = 1;
	}
	else
	{
		ret = cap2_distance;
		dp[cap1][cap2][1] = 2;
	}

	return ret;
}

int main()
{
	cin >> n >> w;

	int r, c;
	incident.push_back({ 1,1 });
	incident.push_back({ n,n });

	for (int i = 0; i < w; i++)
	{
		cin >> r >> c;
		incident.push_back({ r,c });
	}

	memset(dp, -1, sizeof(dp));
	cout << MoveCap(2, 0, 1) << '\n';

	int pos1 = 0;
	int pos2 = 1;

	for (int i = 2; i < w + 2; i++)
	{
		if (dp[pos1][pos2][1] == 1)
		{
			cout << 1 << '\n';
			pos1 = i;
		}
		else
		{
			cout << 2 << '\n';
			pos2 = i;
		}
	}

	return 0;
}

// dp[a][b][0] : distance
// dp[a][b][1] : who move 