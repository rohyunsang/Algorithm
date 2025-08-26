#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Bipartite Graph

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		int v, e;
		cin >> v >> e;
		vector<vector<int>> graph(v + 1);
		for (int i = 0; i < e; i++)
		{
			int st, en;
			cin >> st >> en;
			graph[st].push_back(en);
			graph[en].push_back(st);
		}
		vector<int> color(v + 1, 0);
		bool flag = true;

		for (int s = 1; s <= v && flag; s++)
		{
			if (color[s] != 0) continue;

			queue<int> q;
			color[s] = 1;
			q.push(s);

			while (!q.empty() && flag)
			{
				int cur = q.front();
				q.pop();
				for (int c : graph[cur])
				{
					if (color[c] == 0)
					{
						color[c] = -color[cur];
						q.push(c);
					}
					else if (color[c] == color[cur])
					{
						flag = false;
						break;
					}
				}
			}

			
		}
		if (flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	

	return 0; 
}