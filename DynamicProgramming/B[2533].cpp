// 즉 모든 두 정점 사이에 이들을 잇는 경로가 존재하면서 사이클이 존재하지 않는 경우만 고려한다. 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
	return x.first > y.first;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1);
	vector<int> color(n + 1);
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 루트 노드를 어떻게 정하냐에 따라 다르다. 
	// 친구가 제일 많은 노드부터 처리를 하면? 

	vector<pair<int,int>> friends;

	for (int i = 1; i <= n; i++)
	{
		int s = (int)graph[i].size();
		friends.push_back({ s,i });   // friend size, idx 
	}

	sort(friends.begin(), friends.end(), cmp);

	for (auto f : friends)
	{
		cout << f.first << " " << f.second << endl;
	}

	for (auto f : friends)
	{
		int cur = f.second;
		if (color[cur] == 0)
		{
			color[cur] = 1;
			ans++;
		}
		else
		{
			continue;
		}
		
		for (auto g : graph[cur])
		{
			int next = g;
			if (color[next] == 0)
			{
				color[next] = -1;
			}
		}
	}

	return 0; 
}

// 그리디하게 접근했는데. 트리 DP 였다. 
// 핵심은 각 정점 u에 대해 “u가 얼리냐 / 아니냐” 두 상태를 모두 계산하는 겁니다.