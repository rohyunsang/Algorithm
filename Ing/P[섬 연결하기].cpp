#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int parent[101];

struct cmp {
	bool operator()(pair<int, pair<int, int>> p1, pair<int, pair<int, int>> p2)
	{
		return p1.first > p2.first;
	}
};

priority_queue<pair<int, pair<int, int>>,
	vector<pair<int, pair<int, int>>>, cmp> q;

int GetParent(int node) {
	if (parent[node] == node) return node;
	return parent[node] = GetParent(parent[node]);
}


int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < costs.size(); i++) {
		q.push({ costs[i][2],{costs[i][0],costs[i][1]} });
	}

	cout << q.top().first << q.top().second.first << q.top().second.second << endl;
	q.pop();
	cout << q.top().first << endl;

	for (int i = 0; i < costs.size(); i++) {
		int start = GetParent(q.top().second.first);
		int end = GetParent(q.top().second.second);
		int cost = GetParent(q.top().first);

		if (start != end) {
			answer += cost;
			parent[end] = start;
		}
	}

	return answer;
}
