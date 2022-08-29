#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v_str;
int n; // n < 20,000

bool comp(const string& a ,const string& b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}  // sort comp fuction must satisfy "strict weak ordering "


int main() {
	string s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s; 
		v_str.push_back(s);
	}

	sort(v_str.begin(), v_str.end(),comp);
	v_str.erase(unique(v_str.begin(), v_str.end()), v_str.end());
	

	for (auto v : v_str) {
		cout << v << endl;
	}

	return 0;
}