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

	if (!visited[next]) // �湮���� �ʾҴٸ� 
	{
		dfs(next);
	}
	else if (done[next] == false) // �̹� �湮�ߴٸ� 
	{
		for (int i = next; i != cur; i = students[i])  // ��ģ ����Ŭ ���̵�� 
		{
			noTeam--;
		}
		noTeam--;
	}
	// dfs ȣ�� �������� �ϳ��� cycle ó�� 
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