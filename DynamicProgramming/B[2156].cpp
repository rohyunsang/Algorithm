#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 포도주 잔을 선택하면 다 마시고 원래 위치에 놓기
// 2. 연속으로 3잔불가 최대 2잔 

int main()
{
	int n;
	cin >> n;

	vector<int> v(n+1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	vector<int> d(n + 1);

	d[0] = 0;
	d[1] = v[1];
	d[2] = v[2];

	if (n >= 1) d[1] = v[1];
	if (n >= 2) d[2] = v[1] + v[2];

	for (int i = 3; i <= n; i++)
	{
		// d[i] = max(d[i - 2] + v[i], d[i - 1] + v[i] - v[i - 2]);
		d[i] = max({ d[i - 1], d[i - 2] + v[i], d[i - 3] + v[i - 1] + v[i] });
	}


	cout << d[n];

	return 0;
}

// dp[i] = dp[i-2] + v[i], dp[i-1] + v[i] - v[i-2]

// 1 1 0
// 1 0 1
// 0 1 0 
// 0 1 1 
// 최대 연속 2번 