#include <bits/stdc++.h>

using namespace std;

int N, M; // 1<= N <= 1,000 , 1<= M <= 10,000
int V; //Start at V

vector<int> e[1001];
bool check[1001];


void DFS(const vector<int> &v);
{


}
void BFS(const vector<int>& v);
{
	queue<int> q;
	q.push(v);
	check[v] = true;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < e[cur].size(); i++)
		{
			int next = e[cur][i];
		}
	}

}


int main()
{
	cin >> N >> M >> V;

	DFS(v[V]);
	BFS(v[V]);


	return 0;
}

//https://congcoding.tistory.com/78