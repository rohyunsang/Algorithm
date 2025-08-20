#include <iostream>
#include <vector>

using namespace std;

// Union Find

int n, m;

int parent[1000001]; //MAX
// n x m => Max is 1,000,000
// parent 보단 root 가 더 이해하기 쉬울듯

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



int main() {
	cin >> n >> m;

	for (int i = 0; i <= n * m; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < (int)s.size(); j++)
		{
			if (s[j] == 'U')
			{
				Union(i * m + j, (i - 1) * m + j);
			}
			else if (s[j] == 'D')
			{
				Union(i * m + j, (i + 1) * m + j);
			}
			else if (s[j] == 'R')
			{
				Union(i * m + j, i * m + j + 1);
			}
			else if (s[j] == 'L')
			{
				Union(i * m + j, i * m + j - 1);
			}
		}
	}

	int ans = 0;
	vector<int> seen(n * m, 0);
	for (int v = 0; v < n * m; v++)
	{
		int r = Find(v);
		if (!seen[r])
		{
			seen[r] = 1;
			ans++;
		}
	}
	cout << ans << '\n';

	/* Debug
	for (int i = 0; i < n * m; i++) 
	{ 
		cout << Find(i) << " "; 
		if ((i + 1) % m == 0) cout << endl; 
	}
	*/

	return 0;
}