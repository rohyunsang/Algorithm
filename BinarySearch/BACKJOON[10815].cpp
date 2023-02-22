#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;

vector<int> db;
vector<int> v;

int main() {

	cin >> n;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		db.push_back(tmp);
	}

	cin >> m;
	while (m--)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(db.begin(), db.end());

	for (int i = 0; i < v.size(); i++) {
		if (binary_search(db.begin(), db.end(), v[i]))
			cout << '1';
		else
			cout << '0';
		cout << ' ';
	}


	return 0;
}