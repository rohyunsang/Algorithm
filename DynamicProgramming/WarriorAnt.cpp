#include <bits/stdc++.h>

using namespace std;

int d[10001];
int n;
vector<int> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}

	d[0] = v[0];
	d[1] = max(v[0], v[1]);
	for (int i = 2; i < n; i++) {
		d[i] = max(d[i - 1], d[i - 2] + v[i]);
	}

	//2 1 0
	//3 2 1
	//4 3 2 

	cout << d[n - 1];

	return 0;
}