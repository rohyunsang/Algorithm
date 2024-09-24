#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100001

int d[MAX] = { 0, };


void bfs(int _start, int curTime) {
	queue<pair<int,int>> q;
	q.push({ _start ,0});

	d[_start] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int cur = q.front().second;
		q.pop();

		vector<int> nx;
		nx.push_back(x * 2);
		nx.push_back(x + 1);
		nx.push_back(x - 1);

		for (int i = 0; i < 3; i++) {
			if (nx[i] < 0 || nx[i] > 100000) {
				continue;
			}
			if (i == 0) {
				if (d[nx[i]] > cur) {
					q.push({ nx[i], cur});
					d[nx[i]] = cur;
				}
			}
			else {
				if (d[nx[i]] > cur + 1) {
					q.push({ nx[i], cur + 1 });
					d[nx[i]] = cur + 1;
				}
			}
			
		}
	}
}


int main() {

	int n, k;
	cin >> n >> k;


	fill(d, d + MAX, MAX);
	bfs(n, 0);

	cout << d[k];

	return 0;
}