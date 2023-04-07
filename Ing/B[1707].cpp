#include <iostream>
#include <vector>

using namespace std;

#define RED 2
#define BLUE 3

int T, V, E;
//Bipartite Graph
int u, v;

const int MAX = 20001;
vector<int> node[MAX];
int visited[MAX];

void dfs(int startX) {
	if (!visited[startX])
		visited[startX] = RED;

	for (int i = 0; i < node[startX].size(); i++) {
		int idx = node[startX][i];
		if (!visited[idx])
		{
			if (visited[startX] == RED)
				visited[idx] = BLUE;
			else if (visited[startX] == BLUE)
				visited[idx] = RED;

			dfs(idx);
		}
	}
}

bool CheckingBipartiteGraph() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < node[i].size(); j++) {
			int idx = node[i][j];
			if (visited[i] == visited[idx])
				return false;
		}
	}
	return true;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			cin >> u >> v;
			node[u].push_back(v);
			node[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (!visited[i])
				dfs(i);
		}
		if (CheckingBipartiteGraph())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}





	return 0;
}