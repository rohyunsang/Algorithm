#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[20 + 1][20 + 1] = { 0, };
bool visited[20 + 1] = { false, };
int ans = 1987654321;

// combination ? dfs ? 
// combination으로 뽑아도 dfs를 돌려야?

void dfs(int x, int pos) {

	if (x == n / 2) {
		int start = 0;
		int link = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i] == true && visited[j] == true)
					start += arr[i][j];
				if (visited[i] == false && visited[j] == false)
					link += arr[i][j];
			}
		}
		int nTmp = abs(start - link);
		if (ans > nTmp)
			ans = nTmp;
		return;
	}


	for (int i = pos; i < n; i++) {
		visited[i] = true;
		dfs(x + 1, i + 1);
		visited[i] = false;
	}


}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 1);

	cout << ans;

	return 0;
}