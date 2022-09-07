#include <iostream>
#include <map>
#include <string>

using namespace std;

int n, m;

map<string,string> account;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		account[a] = b;
	}
	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		cout << account[a] << endl;
		
	}

	return 0;
}
