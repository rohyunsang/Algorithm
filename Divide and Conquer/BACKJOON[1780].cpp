#include <bits/stdc++.h>

using namespace std;

int n; // N(1 ≤ N ≤ 3^7, N은 3^k 꼴)
int result[3];
int arr[3 * 3 * 3 * 3 * 3 * 3 * 3 + 1][3 * 3 * 3 * 3 * 3 * 3 * 3 + 1];

// 1. 종이가 같은수 => 종이 그대로
bool check(int row, int col, int num) {
	int start = arr[row][col];
	for (int i = row; i < row + num; i++) {
		for (int j = col; j < col + num; j++) {
			if (start != arr[i][j])
				return false;
		}
	}
	return true;
}

// 2. 종이가 같은수가 아닐시 9로 나누기 
void div(int row, int col, int num) {
	if (check(row, col, num)) {
		result[arr[row][col] + 1]++;
	}
	else {
		int size = num / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				div(row + size * i,  col + size * j, size);
			}
		}
	}

}


int main() {

	cin >> n;

	int tmp;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}

	div(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << result[i] << endl;
	}

	return 0;
}