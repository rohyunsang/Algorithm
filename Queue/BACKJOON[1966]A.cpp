#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> pq;
queue<pair<int, int>> q;

int n, m; // n : 문서의 개수, m : 몇번째 출력 문서
int t;
int cnt = 0;
int main() {
	cin >> t;

	while (t--) {

		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int nTmp;
			cin >> nTmp;
			q.push({ i,nTmp });
			pq.push(nTmp);
		}
		while (!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;

			q.pop();
			if (pq.top() == val) {
				pq.pop();
				cnt++;

				if (idx == m) {
					cout << cnt << endl;
					cnt = 0;
					while (!q.empty())
						q.pop();
					while (!pq.empty())
						pq.pop();
					break;
				}
			}
			else
				q.push({ idx,val });
		}



	}


	return 0;
}