#include <iostream>
#include <set>

using namespace std;

int main() {
	set<int> set1;
	set1.insert(1);
	set1.insert(3);
	set1.insert(2);
	set1.insert(2);
	set1.insert(2);
	set1.insert(2);

	for (auto it = set1.begin(); it != set1.end(); it++) {
		cout << *it << " ";
	}
	
	cout << endl ;

	for (const auto& it : set1)
		cout << it <<" ";
	cout << endl ;
}