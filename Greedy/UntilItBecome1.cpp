#include <iostream>
using namespace std;

int main() {
	int N;
	int K;
	int cnt = 0;
	cin >> N >> K;

	// method 1 N - 1
	// method 2 N / K : Condition N % K == 0
	while (N != 1) {
		if (N % K == 0)
		{
			N = N / K;
			cnt++;
		}
		else
		{
			N = N - 1;
			cnt++;
		}
	}

	cout << cnt;
}