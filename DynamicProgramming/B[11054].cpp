#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;

// DP
int dpRight[1001];
int dpLeft[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}

	for (int i = 0; i < v.size(); i++) {
		dpRight[i] = 1;
		dpLeft[n - 1 - i] = 1;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				dpRight[i] = max(dpRight[i], dpRight[j] + 1);
			}
			if (v[n - 1 - i] > v[n - 1 - j]) {
				dpLeft[n - 1 - i] = max(dpLeft[n - 1 - i], dpLeft[n - 1 - j] + 1);
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < v.size(); i++) {
		ans.push_back(dpRight[i] + dpLeft[i]);
		
	}
	cout << *max_element(ans.begin(), ans.end()) - 1;
	return 0;
}