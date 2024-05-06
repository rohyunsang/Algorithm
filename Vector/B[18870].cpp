#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> vCopy;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}
	vCopy = v;
	sort(v.begin(), v.end());

	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(v.begin(), v.end(), vCopy[i]);

		cout << it - v.begin() << ' ';
	}


	return 0;
}