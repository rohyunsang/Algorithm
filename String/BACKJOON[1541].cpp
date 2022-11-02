#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;

int main() {
	string s;
	cin >> s;

	int result = 0;
	string num;
	bool isMinus = false;

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '-' || s[i] == '+' || i == s.size()) {
			if (isMinus) {
				result -= stoi(num);
				num = ""; //init
			}
			else {
				result += stoi(num); 
				num = ""; //init
			}
		}
		else {
			num += s[i]; // add nums
		}
		if (s[i] == '-') {
			isMinus = true;
		}
	}

	cout << result;

	return 0;
}