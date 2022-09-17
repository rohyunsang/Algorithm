#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int cnt = 0;
int seq[100001];
stack<int> s;
vector<int> v;
vector<char> c;

int n;

// 1 2 3 4 + + + + -
// 1 2 3 -
// 1 2 

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		c.push_back('+');

		while (!v.empty() && v.back() == seq[cnt]) {
			v.pop_back();
			c.push_back('-');
			cnt++;
		}
	}


	if (!v.empty()) cout << "NO";
	else
		for (int i = 0; i < c.size(); i++) {
			cout << c[i] << '\n';
		}

	return 0;
}