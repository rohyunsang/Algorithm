#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n + 1);
	vector<int> ans;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[i] = x;
	}

	ans.push_back(v[0]);

	for (int i = 0; i < n; i++)
	{
		if (ans.back() >= v[i])
		{
			// int idx = *lower_bound(ans.begin(), ans.end(), v[i]);
			auto it = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
			ans[it] = v[i];
		}
		else
		{
			ans.push_back(v[i]);
		}
	}

	cout << (int)ans.size();

	return 0;
}