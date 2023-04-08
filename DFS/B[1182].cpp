#include <iostream>
#include <vector>

using namespace std;

int n, s;
int ans = 0;

// dfs 
// backtracking? 

vector<int> v;

void dfs(int idx, int tmp) {
	if (idx == n)
		return;
	if (tmp + v[idx] == s)
		ans++;
	dfs(idx + 1, tmp);
	dfs(idx + 1, tmp + v[idx]);
}

int main() {
	cin >> n >> s;
	while (n--) {
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}


	return 0;
}