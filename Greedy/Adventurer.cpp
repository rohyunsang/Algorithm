#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	vector<int> arr;
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());

	int group_count = 0;
	int current_adventurer = 0;
	for (int i = 0; i < N; i++)
	{
		cnt++;
		if (cnt >= arr[i]) {
			group_count++;
			cnt = 0;
		}
	}

	cout << group_count;


	return 0;
}