#include <iostream>
#include <algorithm>

using namespace std;

string s;

int main() {
	

	while (true) {
		
		cin >> s;
		string reverse_s = s;
		reverse(reverse_s.begin(), reverse_s.end());

		if (s == "0") break;
		else if (s == reverse_s) cout << "yes\n";
		else cout << "no\n";

	}

	return 0;
}