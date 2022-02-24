#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N;
vector<int> v;

bool comp(int a, int b) {
	return a > b;
}

int main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < N; i++)
	{
		cout << v[i] <<" ";
	}
	return 0;
}