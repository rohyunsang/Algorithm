// �� ��� �� ���� ���̿� �̵��� �մ� ��ΰ� �����ϸ鼭 ����Ŭ�� �������� �ʴ� ��츸 ����Ѵ�. 
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

	// ��Ʈ ��带 ��� ���ϳĿ� ���� �ٸ���. 
	// ģ���� ���� ���� ������ ó���� �ϸ�? 

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

// �׸����ϰ� �����ߴµ�. Ʈ�� DP ����. 
// �ٽ��� �� ���� u�� ���� ��u�� �󸮳� / �ƴϳġ� �� ���¸� ��� ����ϴ� �̴ϴ�.