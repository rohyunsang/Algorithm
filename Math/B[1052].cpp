#include <iostream>
#include <vector> 

using namespace std;

// n <= 10,000,000
// k <= 1,000

// step 1 choose two bottles
// step 2 move one bottle 
// step 3 for step 1, 2


int main() {
	int n;
	cin >> n;   // water bottles
	int k;
	cin >> k;   // max move
	
	// 1 1 1 1 1
	// 2 2 2 2 2
	// 4 4 4 4 4
	// 8 8 8 8 8
	// 16 16 16 16 16 


	if (k >= n)
	{
		cout << 0;
	}
	else
	{
		int ans = 0;

		while (true)
		{
			int cnt = 0;
			int tmp = n;
			while (tmp > 0)
			{
				if (tmp % 2 == 0)
				{
					tmp /= 2;
				}
				else
				{
					tmp /= 2;
					cnt++;
				}
			}

			if (k >= cnt) break;

			n++;
			ans++;
		}
		cout << ans;
	}

	return 0; 
}