#include <iostream>
#include <algorithm>
#include <vector>

//Two Pointer Algorithm

using namespace std;

int n, s;
int cnt = 0;

vector<int> v;

int startIdx = 0;
int endIdx = 0;
int ans = 0;
int sum = 0;

int main() {
	cin >> n >> s;
	int nTmp = n;

	while (nTmp--)
	{
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}
	sum = v[0]; //init
	while (startIdx <= endIdx) {
		int len = endIdx - startIdx + 1;
		if (sum >= s) {
			if (ans == 0) ans = len;
			else if (ans > len) ans = len;
			sum -= v[startIdx];
			startIdx++;
		}
		else if (sum < s)
		{
			endIdx++;
			if (endIdx == n) break; //dangerous if we use while n--
			sum += v[endIdx];
		}
	}

	cout << ans;

	return 0;
}