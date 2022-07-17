#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void PrintVector(vector<int> vector) {
	for (const auto v : vector) {
		cout << v << ' ';
	}
	cout << endl;
}

int main() {
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	PrintVector(v);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()),v.end());

	PrintVector(v);

	return 0;
}