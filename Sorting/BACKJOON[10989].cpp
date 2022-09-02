#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int arr[10001] = {0,};

int main() {

	cin >> t;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < t; i++)
	{
		int tmp;
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < arr[i]; j++) {
			cout << i << "\n";
		}
	}

	return 0;
}