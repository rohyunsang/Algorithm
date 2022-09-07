#include <iostream>
#include <algorithm>

using namespace std;

unsigned int ans;
unsigned int N, K;
unsigned int list[10000];

int BinarySearch(unsigned int list[], int maxi) {
	unsigned int left = 1, right = maxi, mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		unsigned int now = 0;

		for (int i = 0; i < K; i++)
		{
			now += list[i] / mid;
		}

		if (now >= N)
		{
			left = mid + 1;
			ans = max(ans, mid);
		}
		else
		{
			right = mid - 1;
		}
	}

	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	cin >> K >> N;

	unsigned int maxi = 0;

	for (int i = 0; i < K; i++)
	{
		cin >> list[i];
		maxi = max(maxi, list[i]); // 배열에서 최대값
	}

	cout << BinarySearch(list, maxi);
	
}