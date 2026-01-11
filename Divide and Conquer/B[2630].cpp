#include <iostream>

using namespace std;

int map[129][129];

int ans = 0;
int cnt_0 = 0;
int cnt_1 = 0;

void dfs(int x, int y, int size)
{
	bool flag = true;

	int st = map[x][y];

	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (st != map[i][j])
			{
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}

	if (flag == true)
	{
		if (st == 0) cnt_0++;
		if (st == 1) cnt_1++;
		return;
	}

	size = size / 2;

	dfs(x, y + size, size);
	dfs(x, y, size);
	dfs(x + size, y, size);
	dfs(x + size, y + size, size);


}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int cur;
			cin >> cur;
			map[i][j] = cur;
		}
	}

	dfs(0, 0, n);

	cout << cnt_0 << endl;
	cout << cnt_1;

	return 0;
}