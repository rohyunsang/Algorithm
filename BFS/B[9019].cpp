#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

// D : 2n mod 10000
// S : n - 1, if n = 0 then n = 9999
// L : 1 2 3 4 => 2 3 4 1
// R : 1 2 3 4 => 4 1 2 3 

// BFS

bool isVisit[10000];
int a, b;

void BFS() {
	queue<pair<int, string>> q;
	q.push({ a,"" });
	isVisit[a] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string oper = q.front().second; // operate
		q.pop();

		if (num == b)
		{
			cout << oper << endl;
			return;
		}
		int D, S, L, R;

		D = (num * 2) % 10000;
		if (!isVisit[D]) {
			isVisit[D] = true;
			q.push({ D,oper + "D" });
		}

		S = num - 1;
		if (S == -1) S = 9999;

		if (!isVisit[S]) {
			isVisit[S] = true;
			q.push({ S,oper + "S" });
		}

		L = (num % 1000) * 10 + (num / 1000);
		if (!isVisit[L])
		{
			isVisit[L] = !isVisit[L];
			q.push({ L,oper + "L" });
		}

		R = num / 10 + (num % 10) * 1000;
		if (!isVisit[R]) {
			isVisit[R] = true;
			q.push({ R,oper + "R" });
		}
	}
}


int main() {
	int t;
	cin >> t;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (t--) {
		
		cin >> a >> b;
		memset(isVisit, false, sizeof(isVisit));
		BFS();
	}


	return 0;
}