#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K;
	vector<int> arr;
	int sum;
	int offset;

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	sum = arr.back() * M;
	offset = arr.back();
	arr.pop_back();
	offset = offset - arr.back();
	sum = sum - offset * (M / (K + 1));
	cout << sum;

	return 0;
}