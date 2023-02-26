#include <iostream>

using namespace std;

int n;
int k;

int main() {
	cin >> n >> k;
	n--;
	k--;
	long long ans = 1;
	int j = 1;
	for (int i = n; i > n - k; i--) {
		ans *= i;
		ans /= j;
		j++;
	}
	cout << ans;

	return 0;
}


// 3c3 3c2 3c1 3c0
// 4c4 4c3 4c2 4c1 4c0 