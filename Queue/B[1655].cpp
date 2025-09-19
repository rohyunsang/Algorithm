#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	priority_queue<int> left; // ÃÖ´ë Èü 
	priority_queue<int, vector<int>, greater<int>> right; // ÃÖ¼Ò Èü


	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (left.empty() || x <= left.top())
		{
			left.push(x);
		}
		else
		{
			right.push(x);
		}

		if ((int)left.size() > (int)right.size() + 1)
		{
			right.push(left.top());
			left.pop();
		}
		else if (right.size() > left.size())
		{
			left.push(right.top());
			right.pop();
		}

		cout << left.top() << '\n';
	}
}