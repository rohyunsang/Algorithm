#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int ans = 0;

bool CmpIncrease(int x, int y) {
	return x > y;
}

bool CmpDecrease(int x, int y) {
	return x < y;
}

int main() {
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0 ; i < n ;i++) {
		int aNum;
		cin >> aNum;
		a[i] = aNum;
	}

	for (int i = 0; i < n; i++) {
		int bNum;
		cin >> bNum;
		b[i] = bNum;
	}



	sort(a.begin(), a.end(), CmpDecrease);
	sort(b.begin(), b.end(), CmpIncrease);

	for (int i = 0; i < a.size(); i++) {
		ans += a[i] * b[i];
	}

	cout << ans;

	return 0;
}