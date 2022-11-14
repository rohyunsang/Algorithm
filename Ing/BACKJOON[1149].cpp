#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// R G B
// n - 1 != n && n != n + 1 color 

int n; // house

vector<int> nR(1001), nG(1001), nB(1001);

int result = 0;
int minElementTmp;
/*
	3
	26 40 83
	49 60 57
	13 89 99
	pick 26 57 13  
*/ 

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> nR[i] >> nG[i] >> nB[i];
	}
	result += min({ nR[0], nG[0], nB[0] });
	minElementTmp = min({ nR[0], nG[0], nB[0] });

	for (int i = 0; i < n - 1; i++) {
		if (minElementTmp == nR[i]) {
			result += min(nG[i+1], nB[i+1]);
			minElementTmp = min(nG[i+1], nB[i+1]);
		}
		else if (minElementTmp == nG[i]) {
			result += min(nR[i+1], nB[i+1]);
			minElementTmp = min(nR[i+1], nB[i+1]);
		}
		else if(minElementTmp == nB[i]) {
			result += min(nR[i+1], nG[i+1]);
			minElementTmp = min(nR[i+1], nG[i+1]);
		}
	}
	cout << result;

	return 0;
}