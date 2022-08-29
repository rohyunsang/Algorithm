#include <bits/stdc++.h>

using namespace std;

		   //3층의 5호 살려면 2층의 1호 ~ 5호 
int k, n;  //k층의 n호 살려면 k-1 1호 ~ n호
int T;

int apt[15][15];

int main() {

	int result = 0;

	for (int i = 0; i < 14; i++) {
		apt[0][i] = i + 1;
	}

	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 14; j++) {
			result += apt[i][j];
			apt[i + 1][j] = result;
		}
		result = 0;
	}

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << apt[k][n-1] << endl;
	}

	return 0;
}



// 1 2 3
// 1 3 6
// 1 4 10