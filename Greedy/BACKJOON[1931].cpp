#include <iostream>
#include <vector>
#include <algorithm>

//scheduling 

using namespace std;

int n;
int start, end;

vector<pair<int, int>> v;

int main() {

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> ::start >> ::end;
		v.push_back({ ::end, ::start });
	}

	sort(v.begin(), v.end());

	int t = v[0].first;
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (t <= v[i].second) {
			count++;
			t = v[i].first;
		}
	}

	cout << count;

	return 0;
}