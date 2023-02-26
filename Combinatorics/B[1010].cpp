#include <iostream>

using namespace std;

int t;
int n, m;

long long int answer = 1;

int main() {

	cin >> t;

	while (t--) {
		cin >> n >> m;
		int j = 1;
		for (int i = m; i > m - n; i--) {
			answer = answer * i;
			answer = answer / j++;
		}

		cout << answer << endl;
		answer = 1;
	}

	

	// 2c2
	// 5c1
	// 29c13 


	return 0;
}