#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> parent;

int Find(int x) {

	if (parent[x] == x) return x;
	else
	{
		parent[x] = Find(parent[x]);
		return parent[x];
	}
}


void Union(int a, int b) {
	int aParent = Find(a);
	int bParent = Find(b);
	if (aParent != bParent)
	{
		parent[bParent] = aParent;
	}
}


int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++)
	{
		parent.push_back(i);   // parent init self 
	}

	for (int i = 0; i < m; i++)
	{
		int oper, a, b;
		cin >> oper >> a >> b;
		if (oper == 0)   // Union
		{
			Union(a, b);
		}
		else if (oper == 1)  // Find 
		{
			int aParent = Find(a);
			int bParent = Find(b);

			if (aParent != bParent)
			{
				cout << "NO" << '\n';
			}
			else
			{
				cout << "YES" << '\n';
			}
		}
	}


	return 0; 
}