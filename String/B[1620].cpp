#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	map<string, int> si;
	map<int, string> is;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		si[s] = i;
		is[i] = s;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		// isdigit 이거 좋다. 
		if (all_of(s.begin(), s.end(), ::isdigit)) {
			int sInt = stoi(s); 
			cout << is[sInt] << 
				'\n';
		}
		else {
			cout << si[s] << '\n';		}
	}


	return 0;
}