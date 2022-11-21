#include <iostream>
#include <map>
using namespace std;

// key, value

map<string, int> m;

int main() {

	//add pair elements
	m.insert({ "abc", 1 });
	m.insert(make_pair("abc2", 2));

	//cout
	for (const auto& m : m)
		cout << m.first << " " <<m.second <<endl;

	//erase 
	m.erase("abc");
	m.erase("c"); //not occur error
	for (const auto& m : m)
		cout << m.first << " " << m.second << endl;
	if (m.find("abc2") != m.end()) {
		cout << "has key" << endl;
		//change map value
		m["abc2"] = 1004;
	}
	for (const auto& m : m)
		cout << m.first << " " << m.second << endl;



	return 0;
}