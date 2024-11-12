#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int graph[104][104];
const int INF = 987654321;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int st, en, v;
		cin >> st >> en >> v;
		graph[st][en] = min(graph[st][en], v);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF) cout << "0 ";
			else cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

// 플로이드 워셜은 그냥 3중 for문으로 연결해주는 것 