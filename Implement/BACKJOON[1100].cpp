#include <iostream>

using namespace std;

char arr[8][8];
int cnt = 0;

// 0,0 0,2 0,4 0,6
// 1,1 1,3 1,5 1,7
// 2,0 2,2 2,4 2,6
// ...

int main() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> arr[i][j];

			if (((i % 2 == 0 && j % 2 == 0) || 
				(i % 2 != 0 && j % 2 != 0)) 
				&& arr[i][j] == 'F')
				cnt++;
		}
	}

	cout << cnt;

	return 0;
}