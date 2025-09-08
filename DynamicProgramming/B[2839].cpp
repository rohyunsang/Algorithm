#include <iostream>
#include <vector>

using namespace std;

// 3 5 

int main()
{
	int n;
	cin >> n;

	int d[5001] = { 0 };

	for (int i = 0; i <= n; i++)
	{
		d[i] = 987654321;
	}
	d[0] = 0;

	for (int i = 3; i <= n; i++)
	{
		if (d[i - 3] != 987654321)
		{
			d[i] = min(d[i], d[i - 3] + 1);
		}
		if (i >= 5 && d[i - 5] != 987654321)
		{
			d[i] = min(d[i], d[i - 5] + 1);
		}
	}

	if (d[n] == 987654321) cout << -1;
	else cout << d[n];


	return 0;
}