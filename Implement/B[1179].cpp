#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long n;
	long long k;

	cin >> n >> k;

	if (k == 1)
	{
		cout << n;
		return 0;
	}

	long long ans = 0;
	long long i = 1;

	while (i < n)
	{
		long long t = (i - ans - 1) / (k - 1);  // k is not 1 
		if (t <= 0)
		{
			ans = (ans + k) % (i + 1);
			i += 1;
		}
		else
		{
			if (i + t > n)
			{
				t = n - i;
			}
			ans += t * k;
			i += t;
		}
	}

	cout << ans + 1;

	return 0;
}

// 한 바퀴 돌때까지는 똑같음
// 한 바퀴 돌면 이제 k-1 