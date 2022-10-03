#include <iostream>
#include <queue>

using namespace std;

int n; //started 0,0
       // 2 <= n <= 10

bool h[10][10]; // horizontal
bool v[10][10]; // vertical

int arr[10][10];
queue<char> q;

bool outOfRange(const int& x, const int& y) {
	if (x < 0 || x >= n || y < 0 || y >= n)
		return false;

	return true;
}

int main() {

	cin >> n;
	
	int x = 0; // started point
	int y = 0;

	do {
		char cTmp;
		cin >> cTmp;
		q.push(cTmp);

		

		if (q.front() == 'U') {
			if (!outOfRange(x - 1, y)) continue;
			v[x][y] = true;
			v[x--][y] = true;
			
		}
		else if (q.front() == 'D') {
			if (!outOfRange(x + 1, y)) continue;
			v[x][y] = true;
			v[x++][y] = true;
		}
		else if (q.front() == 'L') {
			if (!outOfRange(x + 1, y)) continue;
			h[x][y] = true;
			h[x][y--] = true;
		}
		else if (q.front() == 'R') {
			if (!outOfRange(x + 1, y)) continue;
			h[x][y] = true;
			h[x][y++] = true;
		}
		q.pop();
	} while (!q.empty());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			if (v[i][j] && h[i][j]) cout << "+";
			else if (v[i][j]) cout << "|";
			else if (h[i][j]) cout << "-";
			else cout << ".";
		}
		cout << endl;
	}


	return 0;
}