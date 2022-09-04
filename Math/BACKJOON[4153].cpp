#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(3);

int main() {

	while (1) {
		for (int i = 0; i < 3; i++) {
			cin >> v[i];
		}
		if (v[0] == 0 && v[1] == 0 && v[2] == 0) break;

		sort(v.begin(), v.end());

		if (v[0] * v[0] + v[1] * v[1] == v[2] * v[2])
			cout << "right" << endl;
		else
			cout << "wrong" << endl;

	}
	


	return 0;
}