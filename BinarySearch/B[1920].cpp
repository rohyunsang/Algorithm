#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> v;

int Search(int x, int start, int end) {

	while (start <= end) {
		int mid = (start + end) / 2;
		if (v[mid] > x) {
			end = mid - 1;
		}
		else if (v[mid] < x) {
			start = mid + 1;
		}
		else {
			return 1;
		}
	}

	return 0;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << Search(x, 0, (int)v.size() - 1) << '\n';
	}

	return 0; 
}