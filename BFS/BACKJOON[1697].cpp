#include <iostream>
#include <queue>

using namespace std;

int n, k;
bool isVisit[100000 + 1];

void bfs(int a) {
	queue<pair<int, int>> q;
	q.push({ a,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if (x == k) {
			cout << cnt;
			break;
		}

		if (x + 1 >= 0 && x + 1 < 100001) {
			if (!isVisit[x + 1]) {
				isVisit[x + 1] = true;
				q.push({ x + 1,cnt + 1 });
			}
		}

		if (x - 1 >= 0 && x - 1 < 100001) {
			if (!isVisit[x - 1]) {
				isVisit[x - 1] = true;
				q.push({ x - 1,cnt + 1 });
			}
		}

		if (2 * x >= 0 && 2 * x < 100001) {
			if (!isVisit[2 * x]) {
				isVisit[2 * x] = true;
				q.push({ 2 * x,cnt + 1 });
			}
		}
	}
}

// walking x-1 or x+1
// teleport 2*x


int main() {
	cin >> n >> k;

	isVisit[n] = true;
	bfs(n);	

	return 0;
}