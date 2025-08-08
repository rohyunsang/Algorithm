#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main() {
	string s;
	cin >> s;
	string ans = "";

	stack<char> st;

	for (int i = 0; i < (int)s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			ans += s[i];
		}
		else
		{
			if (s[i] == '(')
			{
				st.push(s[i]);
			}
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!st.empty() && (st.top() == '*' || st.top() == '/'))
				{
					ans += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!st.empty() && st.top() != '(')
				{
					ans += st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			else if (s[i] == ')')
			{
				while (!st.empty() && st.top() != '(')
				{
					ans += st.top();
					st.pop();
				}
				st.pop();
			}
		}
	}
	while (!st.empty())
	{
		ans += st.top();
		st.pop();
	}

	cout << ans;

	return 0;
}