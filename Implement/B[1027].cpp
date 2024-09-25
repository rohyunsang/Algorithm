#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> buildings(n);
	vector<int> cnt(n, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> buildings[i];
	}

	for (int i = 0; i < n; i++) {
		double maxLevel = -2123456789;
		for (int j = i + 1; j < n; j++) {
			double level = (double)(buildings[j] - buildings[i]) / (j - i);
			cout << level << " level" << endl;
			if (level > maxLevel) {
				cnt[i]++;
				cnt[j]++;
				maxLevel = level;
			}
		}
	}

	cout << *max_element(cnt.begin(), cnt.end()) << endl;



	return 0;
}