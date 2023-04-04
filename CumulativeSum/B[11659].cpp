#include <iostream>
#include <vector>

using namespace std;

int n;
int m;
	
vector<long long> v;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		long long llTmp;
		cin >> llTmp;
		v.push_back(v[i - 1] + llTmp);
	}

	while (m--) {
		int i, j;
		cin >> i >> j;
		cout << v[j] - v[i - 1] << '\n';
	}


	return 0;
}