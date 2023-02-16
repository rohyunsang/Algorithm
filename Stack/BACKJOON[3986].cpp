#include <iostream>
#include <stack>

using namespace std;

int main() {
	int t;
	cin >> t;
	int answer = 0;
	while (t--) {
		stack<char> st;
		string s = "";
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (!st.empty() && st.top() == s[i]) {
				st.pop();
			}
			else
				st.push(s[i]);
		}
		if (st.empty())
			answer++;
	}
	cout << answer;
	return 0;
}