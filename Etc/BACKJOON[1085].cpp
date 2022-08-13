#include <iostream>
#include <algorithm>

using namespace std;

int x, y, w, h;

int main() {

	cin >> x >> y >> w >> h;
	// 6 2 10 3 : 1
	// 1 1 5 5  : 1
	
	int tmp1, tmp2;

	tmp1 = min(x, y);
	tmp2 = min(w - x, h - y);

	cout << min(tmp1, tmp2);


	return 0;
}