#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int, pair<int, int>>> graph;
vector<int> parent;

int Find(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Merge(int x, int y)
{
	int x_root = Find(x);
	int y_root = Find(y);

	if (x_root != y_root)
	{
		parent[y_root] = x_root;
	}
}


int main()
{
	int n;
	cin >> n;

	int ans = 0;

	vector<pair<int, int>> _x(n);
	vector<pair<int, int>> _y(n);
	vector<pair<int, int>> _z(n);

	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;

		_x[i] = { x,i };
		_y[i] = { y,i };
		_z[i] = { z,i };
	}

	sort(_x.begin(), _x.end());
	sort(_y.begin(), _y.end());
	sort(_z.begin(), _z.end());


	for (int i = 0; i < n - 1; i++)
	{
		int d = _x[i + 1].first - _x[i].first;
		int st = _x[i].second;
		int en = _x[i + 1].second;
		graph.push_back({ d,{st,en} });

		d = _y[i + 1].first - _y[i].first;
		st = _y[i].second;
		en = _y[i + 1].second;
		graph.push_back({ d,{st,en} });

		d = _z[i + 1].first - _z[i].first;
		st = _z[i].second;
		en = _z[i + 1].second;
		graph.push_back({ d,{st,en} });
	}

	sort(graph.begin(), graph.end());

	parent.resize(n + 1, 0);

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < graph.size(); i++)
	{
		int cost = graph[i].first;
		int x = graph[i].second.first;
		int y = graph[i].second.second;

		if (Find(x) != Find(y))
		{
			Merge(x, y);
			ans += cost;
		}
	}

	cout << ans;

}