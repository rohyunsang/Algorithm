#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 1,000,000
	int d[1'000'002] = { 0 };

	int n;
	cin >> n;

	d[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		int best = d[i - 1] + 1;

		if (i % 2 == 0)
		{
			int cand = d[i / 2] + 1;
			if (cand < best) best = cand;
		}

		if (i % 3 == 0)
		{
			int cand = d[i / 3] + 1;
			if (cand < best) best = cand;
		}

		d[i] = best;
	}

	cout << d[n];

	return 0; 
}