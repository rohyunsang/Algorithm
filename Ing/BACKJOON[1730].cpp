#include <iostream>
#include <queue>

using namespace std;

int n; //started 0,0
       // 2 <= n <= 10

int visit[10][10];
// visit is 0 => .
// visit is 1 => -
// visit is 2 => |
// visit is 3 => +
int arr[10][10];
queue<char> q;

int main() {

	//init visit
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			visit[i][j] = 0;
		}
	}
	
	do {
		char cTmp;
		cin >> cTmp;
		q.push(cTmp);

		int x = 0;
		int y = 0;

		if (q.front() == 'U') {

		}
		else if (q.front() == 'D') {

		}
		else if (q.front() == 'L') {

		}
		else if (q.front() == 'R') {

		}

	} while (!q.empty());


	return 0;
}