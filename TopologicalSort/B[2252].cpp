#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> graph(n + 1);
	vector<int> degree(n + 1);
	queue<int> answer;

	for (int i = 0; i < m; i++) {
		int _start, _end;
		cin >> _start >> _end;
		graph[_start].push_back(_end);
		degree[_end]++;
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			answer.push(i);
		}
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < graph[u].size(); i++) {
			degree[graph[u][i]] -= 1;
			if (degree[graph[u][i]] == 0) {
				q.push(graph[u][i]);
				answer.push(graph[u][i]);
			}
		}
	}

	while (!answer.empty()) {
		cout << answer.front() << " ";
		answer.pop();
	}


	return 0;
}