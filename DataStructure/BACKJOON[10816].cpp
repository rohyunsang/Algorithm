#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;

vector<int> v;
vector<int> answer;


int main() {
	int cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back( tmp);
	}

	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		auto upper = upper_bound(v.begin(), v.end(), tmp);
		auto lower = lower_bound(v.begin(), v.end(), tmp);

		answer.push_back(upper - lower);
	}

	for (auto& ans : answer)
	{
		cout << ans << " ";
	}

	return 0;
}