#include <iostream>
#include <algorithm>

using namespace std;

// DP

int n;
int cur[3], dpMin[3], dpMax[3];

int main() {

	cin >> n;
	for (int i = 0; i < 3; i++) {
		cin >> cur[i];
		dpMin[i] = cur[i];
		dpMax[i] = cur[i];
	}

    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        cur[0] = x;
        cur[1] = y;
        cur[2] = z;

        int max0 = max(dpMax[0], dpMax[1]) + cur[0];
        int max1 = max({ dpMax[0], dpMax[1], dpMax[2] }) + cur[1];
        int max2 = max(dpMax[1], dpMax[2]) + cur[2];

        int min0 = min(dpMin[0], dpMin[1]) + cur[0];
        int min1 = min({ dpMin[0], dpMin[1], dpMin[2] }) + cur[1];
        int min2 = min(dpMin[1], dpMin[2]) + cur[2];

        dpMax[0] = max0;
        dpMax[1] = max1;
        dpMax[2] = max2;

        dpMin[0] = min0;
        dpMin[1] = min1;
        dpMin[2] = min2;
    }

    cout << max({ dpMax[0], dpMax[1], dpMax[2] }) << " ";
    cout << min({ dpMin[0], dpMin[1], dpMin[2] });

	return 0;
}