#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Square 
// 3 4
// 1 2
//p1 p2 p3 p4
//p1.y = p2.y
//p1.x = p3.x
//p2.x = p4.x && p3.y = p4.y

// nC4; 
// next_permutation();
// Nope!!! it is data structure Set

int n;

vector<pair<int, int>> v;

int main() {
	cin >> n;
	while (n--) {
		int nTmp, nTmp2;
		cin >> nTmp >> nTmp2;
		v.push_back({ nTmp,nTmp2 });
	}

	sort(v.begin(), v.end());



	return 0;
}