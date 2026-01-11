#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, powCnt;

long long mat[6][6];
long long tmp[6][6];
long long ans[6][6];

const int DIV_VAlUE = 1000;

void MatMulti(long long x[6][6], long long y[6][6])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tmp[i][j] = 0;
			for (int k = 0; k < n; k++)
			{
				tmp[i][j] += (x[i][k] * y[k][j]);
			}

			tmp[i][j] %= DIV_VAlUE;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			x[i][j] = tmp[i][j];
		}
	}
}

int main()
{
	cin >> n >> powCnt;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
		ans[i][i] = 1; // 정답행렬 단위행렬로 초기화
	}

	while (powCnt > 0)
	{ 
		if (powCnt % 2 == 1)
			MatMulti(ans, mat); 

		MatMulti(mat, mat); 
		powCnt /= 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}



//  x y    p q
//  a b    c d 

// xp + yc, xq + yd
// ap + bc, aq + bd
 

// a^(n+m) = a^n * a^m
// (a x b) mod C => (a mod C x b mod C) mod C 
// 