#include <iostream>
#include <regex>

using namespace std;

int main() {
	string str1 = "hello world";
	cout << str1.replace(0, 5, "By") << endl;

	string str2 = "hello world";
	string str3 = regex_replace(str2, regex("l"), "R");
	cout << str3;
	
}
