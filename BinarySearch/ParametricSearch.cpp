#include <bits/stdc++.h>

using namespace std;
//Parametric Search

int n, m;
vector<int> arr;
int result = 0;

int ParametricSearch(vector<int>& arr){

	int start = 0;
	int end = 1e9;

	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > mid) {
				total += arr[i] - mid;
			}
		}

		if (total < m) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}

	return result;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
	}

	ParametricSearch(arr);

	cout << result;

	return 0;
}