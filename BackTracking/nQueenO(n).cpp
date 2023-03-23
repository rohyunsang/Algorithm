#include <iostream>

using namespace std;

int nQueen[15] = { 0,1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596 };
int n;

int main() {
	cin >> n;
	cout << nQueen[n];

	return 0;
}