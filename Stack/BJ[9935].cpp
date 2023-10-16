#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

int main() {
	string s;
	string bomb; 
	string ans = "";

	cin >> s;
	cin >> bomb;

	for (int i = 0; i < s.size(); i++) {
		ans += s[i];
		if (ans.size() < bomb.size()) continue;

		if (ans.back() == bomb[bomb.size()-1]) {
			
			bool flag = true;
			for (int j = 0; j < bomb.size(); j++) {
				if (ans[ans.size() - bomb.size() + j] != bomb[j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				ans.erase(ans.end() - bomb.size(), ans.end());
			}
		}
	}


	if (ans.empty())
		cout << "FRULA";
	else
		cout << ans;

	return 0;
}