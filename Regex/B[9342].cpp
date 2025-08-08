#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	int t;
	cin >> t;

	// Start A, B, C, D, E, F
	// A
	// F
	// C
	// End A, B, C, D, E, F
	string s;
	while (t--)
	{
		
		cin >> s;
		static const regex re(R"(^[A-F]?A+F+C+[A-F]?$)");
		bool ok = regex_match(s, re);
		cout << (ok ? "Infected!\n" : "Good\n");
	}

	return 0; 
}