#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;


int Find(int cur)
{
	if (cur != parent[cur])
	{
		parent[cur] = Find(parent[cur]);
	}
	return parent[cur];
}

void Union(int x, int y)
{
	int xParent = Find(x);
	int yParent = Find(y);
	if (xParent != yParent)
	{
		parent[yParent] = xParent;
	}
}


int main()
{
	// Init 
	int n;
	int m;
	cin >> n >> m;

	parent.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;

		if (Find(x) == Find(y)) // ����Ŭ �߻� 
		{
			cout << i + 1;
			return 0;
		}
		else
		{
			Union(x, y);
		}
	}

	// ����Ŭ�� �߻����� �ʾ��� ��� .
	cout << 0;


	return 0; 
}