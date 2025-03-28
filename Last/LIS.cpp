#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> arr = { 33,324,1,2,2,2,3,2,32,3,2,5,1 };

	vector<int> v;

	v.push_back(arr[0]);

	int idx = 1;

	while (idx < (int)arr.size())
	{
		if (v.back() < arr[idx])
		{
			v.push_back(arr[idx]);
		}
		else
		{
			int target = lower_bound(v.begin(), v.end(), arr[idx]) - v.begin();
			v[target] = arr[idx];
		}
		idx++;
	}

	cout << v.size() << " : 최장 길이 증가 부분 수열 (LIS) " << endl;

	cout << (int)arr.size() - (int)v.size() + 1 << endl;

	return 0;
}