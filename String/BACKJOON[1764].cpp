#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> v;
vector<string> result;

//upper lower 

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		if (binary_search(v.begin(), v.end(), tmp)) result.push_back(tmp);
	}

	

	cout << result.size() << endl;
	
	sort(result.begin(), result.end());

	for (const auto& res : result) {
		cout << res << endl;
	}

	
	return 0;
}