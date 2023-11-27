#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int t;

// 100,000 C 3 => Time Out

int main() {
	cin >> t;
	while (t--) {
		vector<string> v;
		int n;
		cin >> n;
		int res = 1000000;

		
		for (int i = 0; i < n; i++) {
			string sTmp;
			cin >> sTmp;
			v.push_back(sTmp);
		}

		if (n >= 33) {  // mbti 16 => 16 * 2 초과면 0이 무조건 최소
			cout << 0 << endl;
			continue;
		}

		for (int i = 0; i < n - 2; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				for (int k = j + 1; k < n; k++) {
					int sum = 0;
					for (int x = 0; x < 4; x++) {
						if (v[i][x] != v[j][x]) {
							sum = sum + 1;
						}
						if (v[i][x] != v[k][x]) {
							sum = sum + 1;
						}
						if (v[j][x] != v[k][x]) {
							sum = sum + 1;
						}
					}
					if (sum < res)
						res = sum;
				}
			}
		}
		cout << res << endl;
		v.clear();
	}

	return 0;
}