#include <bits/stdc++.h>

using namespace std;

int N, M; // 1<= N <= 1,000 , 1<= M <= 10,000
int V; //Start at V


bool check[1001]; //DFS
vector<int> v_dfs;
vector<int> v[1000];

bool visit[1001]; //BFS
int arr[1001][1001];


void DFS(int x)  //implement Stack, Recursive
{
	check[x] = true;
	v_dfs.push_back(x);

	for (int i = 0; i < v[x].size(); i++) {
		if (check[v[x][i]]) {
			cout << v[x][i] << " ";
			DFS(v[x][i]);
		}
	}

}

void BFS(int v) //implement Queue
{
	queue<int> q;
	q.push(v);
	visit[v] = true;
	cout << v << " ";

	while (!q.empty()) {
		V = q.front();
		q.pop();

		for (int i = 0; i <= N; i++) {
			if (arr[v][i] == 1 && visit[i] == 0) {
				q.push(i);
				visit[i] = true;
				cout << i << " ";
			}
		}
	}

}


int main()
{
	cin >> N >> M >> V;
	int x, y;

	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}

	DFS(V);

	cout << "start BFS";
	BFS(V);


	return 0;
}

