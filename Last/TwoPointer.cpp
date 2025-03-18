#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main() {
	string s;
	s = "programmerpreorernmofewmrfoeqwrqaoekroasdrprogramsdwmldmwlesalkdlsakdlsarsaprograojqwendjlsandmaemwkmekwmer";
	int rst; // right start
	int ren; // right end
	int lst; // left start
	int len; // left end 

	map<char, int> r_check;
	map<char, int> l_check;

	for (int i = 0; i < (int)s.size(); i++)
	{
		if (s[i] == 'p' || s[i] == 'r' || s[i] == 'o' || s[i] == 'g' || s[i] == 'a' || s[i] == 'm' || s[i] == 'e')
		{
			r_check[s[i]]++;
			if (r_check['p'] >= 1 && r_check['r'] >= 3 && r_check['o'] >= 1 && r_check['g'] >= 1 && r_check['a'] >= 1 && r_check['m'] >= 2 && r_check['e'] >= 1)
			{
				ren = i;
				break;
			}
		}
	}

	for (int i = (int)s.size() - 1; i > 0; i--)
	{
		if (s[i] == 'p' || s[i] == 'r' || s[i] == 'o' || s[i] == 'g' || s[i] == 'a' || s[i] == 'm' || s[i] == 'e')
		{
			l_check[s[i]]++;
			if (l_check['p'] >= 1 && l_check['r'] >= 3 && l_check['o'] >= 1 && l_check['g'] >= 1 && l_check['a'] >= 1 && l_check['m'] >= 2 && l_check['e'] >= 1)
			{
				lst = i;
				break;
			}
		}
	}

	//cout << "lst" << lst << endl;
	//cout << "ren" << ren << endl;

	cout << lst - ren;


	return 0;
}