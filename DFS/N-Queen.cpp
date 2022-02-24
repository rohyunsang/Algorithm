#include <iostream>
#include <cmath>  //double type value absolute
#include <cstdlib>  //int type value absolute

using namespace std;

int board[20], cnt;

void add(int n)
{
	++cnt;
}
int place(int row, int column)
{
	int i;
	for(i = 1; i <=row -1; i++)
	{
		if (board[i] == column)
		{
			return 0;
		}
		else
		{
			if (abs(board[i] - column) == abs(i - row))  //기울기의 절대값
			{
				return 0;
			}
		}
	}
	
	return 1;
}

void queen(int row, int n)
{
	int column;
	for(column = 1; column <= n; ++column)
	{
		if(place(row, column))  //place return == 1 이면 
		{
			board[row] = column;
			if(row == n)
			{
				add(n);  // find solution => call add fuction
			}
			else
			{
				queen(row +1, n);  // not find solution => call queen(row + 1, n); Recursive Fuction
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	queen(1,n);
	cout << "N Queen Algorithm "<< cnt <<endl;
	return 0;
}
