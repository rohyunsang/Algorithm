#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];

int n;
int k;
int cnt = 0;
bool isCheck[101];

void dfs(const int & x) {
	isCheck[x] = true;

	for (auto i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (!isCheck[y]) {
			cnt++;
			dfs(y);
		}
	}
	
}


int main() {
	cin >> n;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	dfs(1);

	cout << cnt;

	return 0;
}