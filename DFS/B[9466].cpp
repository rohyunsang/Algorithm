#include <iostream>
#include <vector>

using namespace std;

vector<int> students;
vector<bool> visited;
vector<bool> done;
int n, t, noTeam;

void dfs(int cur)
{
	visited[cur] = true;
	int next = students[cur];

	if (!visited[next]) // 방문하지 않았다면 
	{
		dfs(next);
	}
	else if (done[next] == false) // 이미 방문했다면 
	{
		for (int i = next; i != cur; i = students[i])  // 미친 사이클 아이디어 
		{
			noTeam--;
		}
		noTeam--;
	}
	// dfs 호출 역순으로 하나씩 cycle 처리 
	done[cur] = true;
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		students = vector<int>(n + 1);
		visited = vector<bool>(n + 1, false);
		done = vector<bool>(n + 1, false);
		noTeam = n;

		for (int i = 1; i <= n; i++)
		{
			cin >> students[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == false)
			{
				dfs(i);
			}
		}

		cout << noTeam << endl;
	}
}