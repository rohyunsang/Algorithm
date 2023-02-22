#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;

int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << '<';
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			if(!q.empty()) q.pop();
		}
		cout << q.front();
		if (q.size() != 1) cout << ", ";
		q.pop();

	}
	cout << '>';

	return 0;
}


// 1 2 3 4 5 6 7
// 1 2 4 5 6 7 
// 1 2 4 5 7 
// 1 4 5 7
// 1 4 5
// 1 4
// 4
//