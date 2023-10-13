#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += (n - i) * v[i];
	}

	cout << ans;


	return 0; 
}