#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair <int, pair<int, int>>> v;

int main(void) {
	v.push_back(make_pair(1, make_pair(2, 3)));
	cout << v[0].first << endl;
	cout << v[0].second.first << endl;
	cout << v[0].second.second;
	return 0;
}

// Console : 1
//         : 2
//         : 3
