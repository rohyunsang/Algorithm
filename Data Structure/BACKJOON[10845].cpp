#include <bits/stdc++.h>

using namespace std;

int N;

int main(void) {

	cin >> N;

	queue<int> q;
	int num;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		if (s == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		else if (s == "pop") {
			if (q.size() != 0) {
				num = q.front();
				q.pop();
			}
			else {
				num = -1;
			}
			cout << num << endl;
		}
		else if (s == "size") {
			cout << q.size() << endl;
		}
		else if (s == "empty") {
			if (q.size() == 0) num = 1;
			else num = 0;
			cout << num << endl;
		}
		else if (s == "front") {
			if (q.size() == 0) {
				num = -1;
			}
			else {
				num = q.front();
			}
			cout << num << endl;
		}
		else if (s == "back") {
			if (q.size() == 0) {
				num = -1;
			}
			else {
				num = q.back();
			}
			cout << num << endl;
		}
	}




	return 0;
}