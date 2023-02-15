#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(false); // backjoon 
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;
	int n; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		while (!st.empty()) {
			if (st.top().second > tmp) {
				cout << st.top().first << ' ';
				break;
			}
			st.pop();
		}
		if (st.empty())
			cout << "0 ";
		st.push({ i,tmp });

	}

	return 0;
}