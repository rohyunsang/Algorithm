#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < v[0].size(); j++) {
			if (v[0][j] != v[i][j])
				v[0][j] = '?';
		}
	}
	cout << v[0];

	return 0;
}