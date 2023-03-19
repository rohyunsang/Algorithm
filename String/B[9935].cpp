#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool flag = true;

string s;
string bomb;
string db = "";

int main() {
	cin >> s;
	cin >> bomb;
	int bombSize = bomb.size();

	for (int i = 0; i < s.size(); i++) {
		db += (s[i]);
		if (db.back() == bomb.back()) {
			flag = true;
			for (int j = 1; j <= bombSize; j++) {
				if (db[db.size() - j] != bomb[bomb.size() - j])
					flag = false;
			}
			if (flag) {
				for (int j = 0; j < bombSize; j++) {
					db.pop_back();
				}
			}
		}
	}

	if (db.empty())
		cout << "FRULA";
	else
		cout << db;

	return 0;
}