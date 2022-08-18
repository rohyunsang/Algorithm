#include <bits/stdc++.h>

using namespace std;

int N; // 0 <= N <= 500

int main() {
	int cnt = 0;
	cin >> N;

	for (int i = 5; i <= N; i *= 5) {
		cnt += N / i;
	}

	cout << cnt;

	return 0;
}

//1! 1
//2! 2
//5! 120
//6! 720
//5 , 2 => 10^2