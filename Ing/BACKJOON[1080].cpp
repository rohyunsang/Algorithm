#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<string> input;
vector<string> target;

void change(vector<string> &v, int x, int y) {
	
	for (; x < x + 3; x++) {
		for (; y < y + 3; y++) {
			v[x][y] = v[x][y] == '1' ? '0' : '1';
		}
	}
}

bool same(const vector<string> input, const vector<string> target, int x, int y) {
	for (int i = 0; i < y; i++) {
		if (input[i] != target[i]) return false;
	}
	return true;
}

int main() {

	int x, y;
	int cnt = 0;
	string sTmp;
	
	cin >> y >> x;
	input.resize(y);
	target.resize(y);

	for (auto& v : input) cin >> v;
	for (auto& v : target) cin >> v;

	for (int i = 0; i < y - 2; i++) {
		for (int j = 0; j < x - 2; j++) {
			if (input[i][j] != target[i][j]) {
				cnt++;
				change(input, i, j);
			}
		}
	}

	cout << (same(input, target, x, y) ? cnt : -1);
	return 0;
}