#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int d[1001][1001] = { 0 };
	string s1;
	string s2;
	cin >> s1 >> s2;

	// int n = (int)s1.size() > (int)s2.size() ? (int)s1.size() : (int)s2.size();


	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else
			{
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}

	/*
	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	*/

	cout << d[(int)s1.size()][(int)s2.size()];


	return 0;
}


//   A C A Y K P
// C 0 1 1 1 1 1  
// A 1 1 2 
// P
// C
// A
// K 



// ´ë°¢¼± 



