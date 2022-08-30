#include <iostream>

using namespace std;

int h, w, n;  // h,w <= 99
int t;

int main() {


	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> h >> w >> n;

		int y = n % h;
		int x = (n / h) + 1;
		if (y == 0) {
			y = h;
			x -= 1;
		}
		
		cout << 100 * y + x << endl;
	}

	return 0;
}