#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;


//1 ������ �ִ� ī�带 ������. 
//2 ������ �ִ� ī�带 ���� �Ʒ���.

// 1 2 3 4
// 2 3 4
// 3 4 2 
// 4 2
// 2 4
// 4

// 1 2 3 4 5
// 2 3 4 5
// 3 4 5 2
// 4 5 2
// 5 2 4
// 2 4
// 4 2
// 2


int main() {
	int cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		if (cnt % 2 == 0) q.pop();
		else {
			q.push(q.front());
			q.pop();
		}
		cnt++;
	}

	cout << q.front();

	return 0;
}
