#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	vector<int> ans;
	ans.push_back(v[0]);

	int cnt = 1;

	for (int i = 1; i < n; i++)
	{
		if (ans.back() < v[i])
		{
			ans.push_back(v[i]);
			cnt++;
		}
		else
		{
			int idx = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
			ans[idx] = v[i];
		}
	}

	cout << cnt; 


	return 0;
}