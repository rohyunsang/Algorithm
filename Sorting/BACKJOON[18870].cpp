#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
vector<int> v_copy;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
		v_copy.push_back(tmp);
	}

	// 2 4 -10 4 -9
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	// -10 - 9 2 4 

	for (int i = 0; i < n; i++) {
		auto it = lower_bound(v.begin(), v.end(), v_copy[i]);

		cout << it - v.begin() << ' ';
	}


	return 0;
}