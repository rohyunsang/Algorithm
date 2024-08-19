#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
//#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v;

	int min = 987654321;

	for (int i = 0; i < n; i++) {
		int nTmp;
		cin >> nTmp;

		v.push_back(nTmp);
	}

	sort(v.begin(), v.end());

	int start = 0;
	int end = (int)v.size() - 1;

	int idx_first;
	int idx_second;

	while (start < end) {
		int sum = v[start] + v[end];

		if (min > abs(sum)) {
			min = abs(sum);
			idx_first = start;
			idx_second = end;

			
		}
		if (sum == 0)
			break;
		if (sum < 0)
			start++;
		else
			end--;
		
	}

	cout << v[idx_first] << " " << v[idx_second];

	return 0;
}