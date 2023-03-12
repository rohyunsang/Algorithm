#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> q;
int sum = 0;

int main() {
	cin >> n;

	while (n--) {
		int nTmp;
		cin >> nTmp;
		q.push(nTmp);
	}

	while (q.size() > 1) {
		int firstTmp = q.top();
		q.pop();
		int secondTmp = q.top();
		q.pop();
		sum += firstTmp + secondTmp;
		q.push(firstTmp + secondTmp);
	}

	cout << sum;

	return 0;
}