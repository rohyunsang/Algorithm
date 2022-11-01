#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}
	sort(v.begin(), v.end());
	for (auto v : v) {
		cout << v << "\n";
	}

	return 0;
}