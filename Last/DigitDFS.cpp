#include <iostream>
#include <string>

using namespace std;

long long target, cntAll = 0;
string answer;
bool found = false;


void dfs_len(int startDigit, int remain, string& cur)
{
	if (found) return;
	if (remain == 0)
	{
		cntAll++;

		if (cntAll == target)
		{
			answer = cur;
			found = true;
		}
		return;
	}
	for (int d = startDigit; d <= 9; ++d)
	{
		cur.push_back(char('0' + d));
		dfs_len(d + 1, remain - 1, cur);
		cur.pop_back();
		if (found) return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	if (!(cin >> target)) return 0;

	const int TOTAL = 1023;
	if (target<1 || target>TOTAL)
	{
		cout << -1 << '\n';
		return 0;
	}

	string cur;
	for (int L = 1; L <= 10 && !found; L++)
	{
		cur.clear();
		dfs_len(0, L, cur);
	}

	cout << answer << '\n';
	return 0;
}