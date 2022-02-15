#include <bits/stdc++.h>
#include <string>

using namespace std;

int main(void)
{
	//[row][column]
	string dot;
	cin >> dot;
	
	int x[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	int y[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	
	int result = 0;

	//int row = dot[1]; 
	//int col = dot[1] - '1'; => int implicit type conversion? 

	int row = dot[1] - '0';
	int col = dot[0] - 'a' + 1;

	int arr[1][2] = { row , col };
	for (int i = 0; i < 8; i++) {
		int moveRow = row + x[i];
		int moveCol = col + y[i];
		if (moveRow >= 1 && moveRow <= 8 && moveCol >= 1 && moveCol <= 8)
			result += 1;
	}

	cout << result;

	return 0;
}