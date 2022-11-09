#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	vector<int> v(2550000);
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int nTmp;
		cin >> nTmp;
		v[i] = nTmp;
	}
	sort(v.begin(), v.end(), greater<int>());
	cout << v[n - 1];
	return 0;
}