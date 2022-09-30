#include <iostream>

using namespace std;

int n, m;
int k;

int a[100+1][100+1];
int b[100 + 1][100 + 1];
int r[100 + 1][100 + 1];

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			a[i][j] = tmp;
		}
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			b[i][j] = tmp;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int u = 0; u < m; u++)
				r[i][j] += a[i][u] * b[u][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << r[i][j] << " ";
		cout << endl;
	}


	return 0;
}
