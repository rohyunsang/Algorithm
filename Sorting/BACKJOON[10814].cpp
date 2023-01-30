#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int t;
vector<pair<int, string>> v;

bool cmp(const pair<int, string> &p1, const pair<int, string> &p2) {
	return p1.first < p2.first;
}

int main() {
	cin >> t;

	while (t--) {
		int nTmp;
		string sTmp = "";
		cin >> nTmp >> sTmp;
		v.push_back({ nTmp,sTmp });
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (const auto& v : v) {
		cout << v.first << ' ' << v.second << '\n';
		// recommend '\n' than endl
	}




	return 0;
}