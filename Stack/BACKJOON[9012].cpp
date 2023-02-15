#include <iostream>
#include <stack>

using namespace std;

int t;


int main() {

	cin >> t;

	while (t--) {
		stack<char> st;
		string s;
		string answer = "YES";
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')
				st.push('(');
			else if (!st.empty() && s[i] == ')' && st.top() == '(')
			{
				st.pop();
			}
			else
			{
				answer = "NO";
				break;
			}
		}
		if (!st.empty())
			answer = "NO";
		cout << answer << endl;

	}


	return 0;
}