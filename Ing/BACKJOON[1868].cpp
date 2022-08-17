#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[50001];
int n;

int dfs(int n)
{

}

int main() {

	cin >> n;
	int x, y;
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	// 1 2
	// 2 3
	// 4 3
	// 5 3 


	return 0;
}