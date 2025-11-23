#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[500000];

int Find(int cur)
{
	if (cur == p[cur]) 
		return cur;
	else 
		return Find(p[cur]);

}

void Union(int x, int y)
{
	int parentX = Find(x);
	int parentY = Find(y);

	p[parentY] = parentX;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int ans = 0;

	for (int i = 0; i < n; i++)
	{
		p[i] = i;  //init self parent 
	}

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		if (Find(x) == Find(y))
		{
			// cycle 
			ans = i + 1;
			break;
		}
		else
		{
			// cout << x << " " << y << " not same parent " << i << endl;
			Union(x, y);
		}
	}

	cout << ans; 

	return 0; 
}

// each node same parent state 
// union -> cycle 