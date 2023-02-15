#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	//stack<int> st;
	vector<int> v;
	vector<int> answer;

	for (int i = 0; i < n; i++) {
		int nTmp;
		cin >> nTmp;
		v.push_back(nTmp);
	}
	

	// v[i] v[j]
	//   3    2
	//   3    1 
	//   3    0
	answer.push_back(0);
	for (int i = 1; i < v.size() ; i++) {
		int aSize = answer.size();
		for (int j = i - 1; j >= 0; j--) {
			if (v[j] >= v[i]) {
				answer.push_back(j + 1);
				break;
			}
		}
		if (answer.size() == aSize)
			answer.push_back(0);
	}

	for (const auto a : answer)
		cout << a << ' ';

}