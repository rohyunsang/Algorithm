#include <bits/stdc++.h>

using namespace std;

		   //3���� 5ȣ ����� 2���� 1ȣ ~ 5ȣ 
int k, n;  //k���� nȣ ����� k-1 1ȣ ~ nȣ
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