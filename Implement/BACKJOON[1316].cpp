#include <iostream>

using namespace std;

int n;
int cnt = 0;
string str;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		bool flag = true;

		for (int j = 0; j < str.length(); j++) {
			for (int k = 0; k < j; k++) {
				if (str[j] != str[j - 1] && str[j] == str[k]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) cnt++;
	}

	cout << cnt;

	return 0;
}
