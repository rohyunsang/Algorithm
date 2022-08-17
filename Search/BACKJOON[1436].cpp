#include <iostream>
#include <vector>

using namespace std;

int N; // N <=10000

int main() {
	int cnt = 0;
	cin >> N;
	
	for (int i = 666;;i++) {
		int tmp = i;
		while (tmp >= 666)
		{
			if (tmp % 1000 == 666) {
				cnt++;
				break;
			}
			tmp = tmp / 10;
		}
		if (N == cnt) {
			cout << i;
			break;
		}
		
	}

	return 0;
}