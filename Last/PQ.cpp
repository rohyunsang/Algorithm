#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	vector<int> weights = { 30,20,25 };
	int n = (int)weights.size();
	int d = 4;

	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		pq.push(weights[i]);
	}

	while (d--)
	{
		int cur = pq.top();
		if (cur > 1)
		{
			pq.pop();
			pq.push(cur - (cur / 2));
			cout << (cur - (cur / 2)) << " ";
			
		}
	}

	int ans = 0;

	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}


	cout << ans; 


	return 0;
}