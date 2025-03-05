#include <iostream>

using namespace std;

int g[101][101];

int main() {
	int n; 
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> g[i][j];
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (g[i][k] && g[k][j])  // 1 -> 2 -> 3 : 1 - 3 플로이드와샬
				{
					g[i][j] = 1;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << g[i][j] << " ";
		}
		cout << endl;
	}

}