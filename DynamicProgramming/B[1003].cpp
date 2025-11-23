#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt_0 = 0;
int cnt_1 = 0;

int fibo(int n)
{
	if (n == 0)
	{
		cnt_0++;
		return 0;
	}
	else if (n == 1)
	{
		cnt_1++;
		return 1;
	}
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	}

	return 0; 
}

int main()
{
	/*    TEST
	
	for (int i = 0; i < 10; i++)
	{
		fibo(i);
		cout << cnt_0 << "   " << cnt_1 << endl;
		cnt_0 = 0;
		cnt_1 = 0;
	}

	*/


	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int d0[41] = { 0 };
		int d1[41] = { 0 };
		d0[0] = 1;
		d0[1] = 0;
		d1[0] = 0;
		d1[1] = 1;

		if (n >= 2)
		{
			// normal case 
			for (int i = 2; i <= n; i++)
			{
				d0[i] = d0[i - 1] + d0[i - 2];
				d1[i] = d1[i - 1] + d1[i - 2];
			}
			cout << d0[n] << " " << d1[n] << endl;
		}
		else if (n == 1)
		{
			cout << 0 << " " << 1 << endl;
		}
		else if (n == 0)
		{
			cout << 1 << " " << 0 << endl;
		}

	}




	return 0;
}


/*
1   0
0   1
1   1
1   2
2   3
3   5
5   8
8   13
13   21
21   34
*/
