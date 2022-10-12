#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> answer;
int n, m;
// pop first elements
// right push : cost++
// left push  : cost++

int main() {

	cin >> n >> m;

	for (auto i = 1; i <= n; i++)
	{
		v.push_back(i); //init 
	}
	for (auto i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		answer.push_back(tmp);
	}

	while (m--) {
		for (int i = 0; i < n; i++) {
			if (v[i] == answer[m-1]) // delete[i]; and break
			{
				v.erase(v.begin() + i);
				break;
			}
			else {
				// n - answer[m-1] or answer[m-1] what's bigger
				if(n-answer[m-1])
			}
		}
	}

	return 0;

}