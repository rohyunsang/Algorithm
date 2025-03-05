#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<int> oper;

int ansMax = -1000000000;
int ansMin =  1000000000;

int n;

void dfs(int res, int idx) {

	if (idx == n)
	{
		if (res > ansMax) ansMax = res;
		if (res < ansMin) ansMin = res;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] > 0)
		{
			oper[i]--;
			if (i == 0) dfs(res + num[idx], idx + 1);
			else if (i == 1) dfs(res - num[idx], idx + 1);
			else if (i == 2) dfs(res * num[idx], idx + 1);
			else if (i == 3) dfs(res / num[idx], idx + 1);
			oper[i]++;
		}
	}
	return;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		num.push_back(x);
	}

	for (int i = 0; i < 4; i++)
	{
		int x;
		cin >> x;
		oper.push_back(x);
	}


	dfs(num[0], 1);

	cout << ansMax << endl;
	cout << ansMin;


	return 0;
}