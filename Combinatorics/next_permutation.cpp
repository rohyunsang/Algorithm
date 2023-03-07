#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	next_permutation(v.begin(), v.end());

	while (next_permutation(v.begin(), v.end()))
	{
		for (auto it = v.begin(); it != v.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	return 0;
}