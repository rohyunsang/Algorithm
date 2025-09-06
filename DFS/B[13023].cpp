#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 문제가 난해한데, dfs 깊이가 4이상만 되면 되는거다. 


vector<int> v[2000];
bool visited[2000];
bool ispossible;

void dfs(int node, int depth)
{
	if (depth == 4)
	{
		ispossible = true;
		return;
	}
	visited[node] = true;
	for (auto next : v[node])
	{
		if (visited[next] == false && !ispossible)
		{
			dfs(next, depth + 1);
		}
	}
	visited[node] = false;
}

int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int st, en;
		cin >> st >> en;

		v[st].push_back(en);
		v[en].push_back(st);
	}

	for (int i = 0; i < n; i++)
	{
		dfs(i, 0);
		if (ispossible) break;
	}

	cout << ispossible;

	return 0;
}

