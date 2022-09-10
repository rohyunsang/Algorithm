#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int t, n, m;

// 4 2 : 4개의 문서가 있고 2번째꺼가 언제 출력
// 1 2 3 4 : 중요도

// 6 0 : 6개의 문서가 있고 0번째꺼가 언제 출력
// 1 1 9 1 1 1 : 중요도 


int main() {

	cin >> t;

	while (t--) {
		queue<pair<int, int>> q;
		vector<int> v;
		int cnt = 0;

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			if (i == m) {
				q.push(make_pair(tmp,1));
			}
			else {
				q.push(make_pair(tmp, 0));
			}
		}

		sort(v.begin(), v.end());

		while (true) {
			if (v.back() == q.front().first) {
				if (q.front().second == 1) {
					cnt++;
					break;
				}
				else {
					v.pop_back();
					q.pop();
					cnt++; 
				}
			}
			else {
				q.push(make_pair(q.front().first, q.front().second));
				q.pop();
			}
		}
		cout << cnt << endl;

	}


	return 0;
}