#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> v[101];
int g[101][101] = { 0, };
queue<int> q;

int n, m; // n is user cnt, m is friend cnt
int sum = 0, result = 0;
int min = pow(2, 31) - 1;

void bfs(int start) {
	int v[101] = { 0, }; //init
	q.push(start);
	v[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {

		}
	}
}

int main() {
	cin >> n >> m;
	while (m--) {
		int nTmpX;
		int nTmpY;
		cin >> nTmpX >> nTmpY;
		v[nTmpX].push_back(nTmpY);
		v[nTmpY].push_back(nTmpX);
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}


	return 0;
}