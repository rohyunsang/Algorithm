#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int m;

const int MAX = 100 + 1;

vector <int> v[MAX];
int result[MAX][MAX] = { 0, };
queue<int> q;

int sum = 0;
int ans = 0;
int min_num = 1987654321;

void bfs(int start) {
	int d[MAX] = { 0, };
	q.push(start);
	d[start] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int idx = v[x][i];
			if (d[idx] == 0) {
				d[idx] = 1;
				q.push(idx);
				result[idx][start] = result[x][start] + 1;
				result[start][idx] = result[start][x] + 1;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int nTmp, nTmp2;
		cin >> nTmp >> nTmp2;
		v[nTmp].push_back(nTmp2);
		v[nTmp2].push_back(nTmp);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			result[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++)
		bfs(i);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += result[i][j];
		}
		if (min_num > sum) {
			min_num = sum;
			min_num = i;
		}
	}

	cout << result;

	return 0;
 }