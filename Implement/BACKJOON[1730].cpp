#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n; //started 0,0
	   // 2 <= n <= 10

bool h[100][100]; // horizontal
bool v[100][100]; // vertical

string s;

bool outOfRange(const int& x, const int& y) {
	if (x < 0 || x >= n || y < 0 || y >= n)
		return false;

	return true;
}

int main() {

	cin >> n;
	cin >> s;
	int x = 0; // started point
	int y = 0;

	
	for (int i = 0; i < s.size();i++) {

		if (s[i] == 'U') {
			if (!outOfRange(x - 1, y)) continue;
			v[x][y] = true;
			v[--x][y] = true;

		}
		else if (s[i] == 'D') {
			if (!outOfRange(x + 1, y)) continue;
			v[x][y] = true;
			v[++x][y] = true;
		}
		else if (s[i] == 'L') {
			if (!outOfRange(x, y-1)) continue;
			h[x][y] = true;
			h[x][--y] = true;
		}
		else if (s[i] == 'R') {
			if (!outOfRange(x , y+1)) continue;
			h[x][y] = true;
			h[x][++y] = true;
		}
	} 

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