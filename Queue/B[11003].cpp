#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, d;
	cin >> n >> d;

	priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		pq.push({ x,i });

		int st = i - d + 1;
		// st가 0 미만이어도 가능 
		while (!pq.empty() && pq.top().second < st)
		{
			pq.pop();
		}
		cout << pq.top().first;
		cout << ' ';


	}
	return 0;
}