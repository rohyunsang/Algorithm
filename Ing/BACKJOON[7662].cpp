#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int t, k;

// I N : N을 Q에 넣어라
// D 1 : Q에서 최대값을 삭제
// D -1 : Q에서 최소값을 삭제
// if empty queue => operator D : continue

//우선순위 Queue는 말 그대로 우선순위에 따라 정렬된 Queue이다
priority_queue<int, vector<int>,greater<int>> min_pq; 
priority_queue<int, vector<int>,less<int>> max_pq; 
map<int, int> db;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t) {
		cin >> k;
		for (int i = 0; k < i; i++) {
			string a;
			int b;
			cin >> a >> b;
			if (a == "I") {
				min_pq.push(b);
				max_pq.push(b);
			}
			else if (a == "D" && b == 1) {
				max_pq.pop();

			}
			else if (a == "D" && b == -1) {
				min_pq.pop();
			}
		}
	}

	return 0;
}
