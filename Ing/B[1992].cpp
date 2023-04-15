#include <iostream>
#include <vector>

using namespace std;

const int MAX = 64 + 1;
int n;
int map[MAX][MAX];

void dfs(int x, int y, int size) {
	if (size == 1) {
		cout << map[x][y];
		return;
	}

	bool isAllOne = true;
	bool isAllZero = true;

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] == 0) isAllOne = false;
			if (map[i][j] == 1) isAllZero = false;
		}
	}

	if (isAllOne)
	{
		cout << 0;
		return;
	}
	if (isAllZero) {
		cout << 1;
		return;
	}
	cout << '(';
	dfs(x, y, size / 2);
	dfs(x, y + size / 2, size / 2);
	dfs(x + size / 2, y, size / 2);
	dfs(x + size / 2, y + size / 2, size / 2);
	cout << ')';

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string sTmp;
		cin >> sTmp;
		for (int j = 0; j < sTmp.size(); j++) {
			map[i][j] = sTmp[j] - '0';
		}
	}
	dfs(0, 0, n);

	return 0;
}