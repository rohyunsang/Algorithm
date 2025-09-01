#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t;

void dfs(int cur, vector<int>& graph, vector<bool>& visited, vector<bool>& cycleStudents, int& team)
{
	// dfs는 처음부터 방문했다고 처리해야함. 
	// bfs는 queue에 넣을떄 방문처리. 
	visited[cur] = true;
	int next = graph[cur];

	if (visited[next] == false)
	{
		dfs(next, graph, visited, cycleStudents, team);
	}
	else if (cycleStudents[next] == false) // cycle student가 아닐경우 
	{
		for (int i = next; i != cur; i = graph[i])
		{
			team++; 
		}

		team++;  // 자신까지 포함 
	}

	cycleStudents[cur] = true;
}

int main()
{
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		vector<int> graph(n + 1);
		vector<bool> visited(n + 1);
		vector<bool> cycleStudents(n + 1);

		int team = 0;

		for (int i = 1; i <= n; i++)
		{
			int tmp;
			cin >> tmp;
			graph[i] = tmp;
		}

		for (int i = 1; i <= n; i++)
		{
			dfs(i, graph, visited, cycleStudents, team);
		}

		cout << n - team << '\n';
	}

	return 0; 
}