#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<long long> v;
	
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	queue<long long> q;

	for(int i = 1; i < 10; i++)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		long long num = q.front();
		int last = num % 10;
		q.pop();

		for (int i = 0; i < last; i++)
		{
			long long nextNum = num * 10 + i;
			q.push(nextNum);
			v.push_back(nextNum);
		}
	}

	if (n >= (int)v.size())
		cout << -1;
	else
		cout << v[n];




	return 0;
}