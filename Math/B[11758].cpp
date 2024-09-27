#include <iostream>
#include <vector>

using namespace std;

int main() {

	int x1, x2, x3;
	int y1, y2, y3;

	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	auto result = (x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3);

	if (result > 0) cout << 1;
	else if (result < 0) cout << -1;
	else cout << 0;

	return 0;
}