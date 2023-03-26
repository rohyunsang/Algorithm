#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 9;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { false, };
//back tracking

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}


int main() {

	cin >> n >> m;
	dfs(0);

	return 0;
}