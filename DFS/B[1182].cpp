#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int s;
int cnt = 0; 

vector<int> v;

void dfs(int idx, int tmp) {
	if (idx == n) return;
	if (tmp + v[idx] == s) cnt++;

	dfs(idx + 1, tmp);
	dfs(idx + 1, tmp + v[idx]);
}

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}
	dfs(0, 0);
	cout << cnt;

	/*do {
		for (int i = 0; i < 3; i++)
			cout << v[i] << " ";
		cout << '\n';

	} while (next_permutation(v.begin(), v.end()));*/


	return 0;
}