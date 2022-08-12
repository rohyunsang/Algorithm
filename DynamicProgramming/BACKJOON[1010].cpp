#include <iostream>
#include <vector>

using namespace std;

int T, N, M;

int main()
{
	cin >> T;

	vector<int> l_bridge;
	vector<int> r_bridge;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		l_bridge.push_back(N);
		r_bridge.push_back(M);
	}

	long long com_Init;

	// M combination N
	for (int i = 0; i < T; i++)
	{
		com_Init = 1;
		int r = 1;
		for (int j = r_bridge[i]; j > r_bridge[i]-l_bridge[i]; j--)
		{
			com_Init *= j;
			com_Init /= r++;
		}
		
		cout << com_Init << endl;
		
	}
	return 0;
}