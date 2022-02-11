#include <iostream>
using namespace std;

int main(void)
{
	int coinTypes[] = { 500, 100, 50, 10 };
	int cnt = 0;
	int N;
	cin >> N;

	for (int i = 0; i < 4; i++)
	{
		cnt = cnt + N / coinTypes[i];
		N = N % coinTypes[i];
	}

	cout << "필요한 동전의 개수: " << cnt;

	return 0;
}