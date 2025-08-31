#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string BarLoop(int cnt) {
	string let = "";
	while (cnt--)
	{
		let += "--";
	}
	return let;
}

int main() 
{
	int n;
	cin >> n;

	vector<vector<string>> s(n);
	
	for (int i = 0; i < n; i++)
	{
		int cnt;
		cin >> cnt;
		vector<string> sTmp;
		for (int j = 0; j < cnt; j++)
		{
			string tmp;
			cin >> tmp;
			sTmp.push_back(tmp);
		}
		s[i] = sTmp;
	}

	sort(s.begin(), s.end());
	/*
	for (auto s : s)
	{
		cout << endl;
		for (auto s : s)
		{
			cout << s << " ";
		}
	}
	
	cout << endl;
	*/
	for (int i = 0; i < n; i++)
	{
		int dep = 0;
		if (i != 0)
		{
			for (int j = 0; j < s[i].size() && j < s[i - 1].size(); j++)
			{
				if (s[i][j] == s[i - 1][j])
				{
					dep++;
				}
				else
				{
					break;
				}
			}

		}
		
		for (int j = dep; j < s[i].size(); j++)
		{
			cout << BarLoop(j);
			cout << s[i][j] << endl;
		}
	}

	

	return 0; 
}




/*
APPLE APPLE
APPLE BANANA KIWI
KIWI APPLE
KIWI BANANA

APPLE
--APPLE
--BANANA
----KIWI
KIWI
--APPLE
--BANANA
*/