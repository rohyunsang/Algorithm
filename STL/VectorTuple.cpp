#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector < tuple<int, int, int>> v;

int main(void) {
	
	v.push_back(make_tuple(1, 2, 3));

	cout << get<0>(v[0]) << endl;
	cout << get<1>(v[0]) << endl;
	cout << get<2>(v[0]) << endl;
	
	return 0;
}

// Console : 1
//         : 2
//         : 3

