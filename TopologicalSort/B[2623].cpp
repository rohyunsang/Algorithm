#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> data(n+1);
	vector<vector<int>> graph(n+1);
	vector<int> degree(n+1);

	queue<int> ans;
	

	for (int i = 0; i < m; i++) {
		int loopCnt;
		cin >> loopCnt;

		vector<int> vTmp;
		for (int j = 0; j < loopCnt; j++) {
			int nTmpInner;
			cin >> nTmpInner;
			vTmp.push_back(nTmpInner);
		}

		for (int j = 0; j < (int)vTmp.size() - 1; j++) {
			graph[vTmp[j]].push_back(vTmp[j + 1]);
			degree[vTmp[j + 1]]++;
		}
	}

	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			q.push(i);
			ans.push(i);
		}
	}


	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : graph[cur]) {
			degree[next]--;
			if (degree[next] == 0) {
				q.push(next);
				ans.push(next);
			}
		}
	}

	if (ans.size() != n) {
		cout << 0 << endl;
		return 0;
	}
	
	while (!ans.empty()) {
		cout << ans.front() << endl;
		ans.pop();
	}


	return 0; 
}