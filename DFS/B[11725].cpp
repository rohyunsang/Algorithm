#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100001

// vector<vector<int>> v(MAX);
vector<int> v[MAX];
bool isVisited[MAX] = { false };
// bool isVisited[MAX] = { false, }; 위와 같음
int d[MAX] = { 0 };

void dfs(int _start) {
	isVisited[_start] = true;
	for (int i = 0; i < v[_start].size(); i++) {
		int next = v[_start][i];
		if (isVisited[next] == false) {
			d[next] = _start;
			dfs(next);
		}
	}
}

int main() {
	int n;
	cin >> n;


	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= n; i++)
		cout << d[i] << '\n';

	return 0; 
}