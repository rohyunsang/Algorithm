#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100000 + 2


int d[MAX] = {0,};
int cnt[MAX] = { 0, };

void bfs(int start) {
	queue<int> q;
	q.push(start);
	d[start] = 0;
	cnt[start] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int nx;
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				nx = x - 1;
			}
			else if (i == 1) {
				nx = x + 1;
			}
			else if (i == 2) {
				nx = x * 2;
			}

			if (nx > MAX || nx < 0) continue;

			if (d[nx] != -1) {
				if (d[x] + 1 == d[nx]) {
					cnt[nx] += cnt[x];
				}
			}
			else {
				d[nx] = d[x] + 1;
				cnt[nx] = cnt[x];
				q.push(nx);

			}

		}
	}


}

int main() {
	int n, k;
	cin >> n >> k;

	fill(d, d + MAX, -1);

	bfs(n);

	cout << d[k] << endl;
	cout << cnt[k];

	return 0;
}
