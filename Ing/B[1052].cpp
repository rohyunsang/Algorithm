#include <iostream>

using namespace std;

int n; 
int k;
int res;
int cnt = 0;

// 3 1 : 1 1 1 => 1 1 1 1 => 2 2 => 4 
// do : pick same both things and pour water 
// do : purchase 1 liter

int main() {
	cin >> n >> k;

	if (n <= k) {
		cout << '0' << '\n';
		return 0;
	}
	while (true) {
		int nTmp = n;
		while (nTmp) {
			if (nTmp % 2 == 1) {
				cnt++;
			}
			nTmp = nTmp / 2;
		}
		if (cnt <= k)
			break;
		res++;
	}
	
	cout << res;


	return 0;
}