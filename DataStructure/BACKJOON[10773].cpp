#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<int> v;

int main() {
	cin >> k;

	int sum = 0;
	for (auto i = 0; i < k; i++)
	{
		int tmp;
		cin >> tmp;

		if (tmp == 0) {
			v.pop_back();
		}else v.push_back(tmp);

	}

	for (auto const & v : v) {
		sum += v;
	}

	cout << sum;

	return 0;
}