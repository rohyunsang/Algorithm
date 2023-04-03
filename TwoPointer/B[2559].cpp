#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
int sum = 0;
vector<int> v;
vector<int> sumV;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}

	for (int i = 0; i < k; i++) { //init 
		sum += v[i];
	}

	sumV.push_back(sum);
	for (int i = 0; i < n - k; i++) {
		sum -= v[i];
		sum += v[i + k];
		sumV.push_back(sum);
	}

	sort(sumV.begin(), sumV.end());
	cout << sumV[sumV.size() - 1];


	return 0;
}