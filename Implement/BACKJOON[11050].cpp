//Binomial Coeffcient

#include <iostream>

using namespace std;

int n, k;

int factorial(int n) {
	int ans = 1;
	for (int i = n; i > 0; i--) {
		ans *= i;
	}
	return ans;
}


int main() {

	cin >> n >> k;
	// (a + b)^n = (a+b)(a+b) ... (a+b)
	// a^r*b^(n-r) n! * 1 / r!(n-r)!
	// n k = nCk

	cout << factorial(n) / (factorial(k) * factorial(n - k));

	return 0;
}