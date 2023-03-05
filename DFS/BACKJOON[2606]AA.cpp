#include <iostream>
#include <vector>

using namespace std;

int numComputer;
int connectComputer;
vector<int> v[101];
bool check[101];

int cnt = 0;

void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (!check[next]) {
			dfs(next);
			cnt++;
		}
	}
}

int main() {
	cin >> numComputer;
	cin >> connectComputer;

	int x, y;

	for (int i = 0; i < connectComputer; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout << cnt;
	return 0;
}