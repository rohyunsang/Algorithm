#include <iostream>

using namespace std;

int n, m;

#define MAX 9
int arr[MAX] = { 0 };
bool visited[MAX] = { false };

void dfs(int num, int depth) {
	if (depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) {
		visited[i] = true;
		arr[depth] = i;
		dfs(i, depth + 1);
		visited[i] = false;
	}

}

int main() {

	cin >> n >> m;

	dfs(1, 0);


	return 0;
}