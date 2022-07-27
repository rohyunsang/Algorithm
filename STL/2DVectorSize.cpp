#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
int main()
{
	v.push_back(vector<int>());
	v[0].push_back(1);
	v[0].push_back(2);
	v[0].push_back(3);
	v.push_back(vector<int>());
	v[1].push_back(4);
	v[1].push_back(5);
	v[1].push_back(6);

	cout << v[0][1] <<" " << v[1][1] << endl;

	cout << v.size() << endl;
	cout << v[0].size();
	return 0;
}


