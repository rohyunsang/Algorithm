#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> g[100001];

bool visited[100001] = { false, };

int firstArrival; 
int d = 0; 

void dfs(int cur, int cnt) {

    if (d < cnt)
    {
        firstArrival = cur;
        d = cnt;
    }

    for (int i = 0; i < g[cur].size(); i++)
    {
        int nx = g[cur][i].first;
        int cost = g[cur][i].second;
        if (!visited[nx])
        {
            visited[nx] = true;
            dfs(nx, cnt + cost);
            visited[nx] = false;
        }
    }
}


int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int u, v, cost;
        cin >> u;
        while (true)
        {
            cin >> v;
            if (v == -1) break;
            cin >> cost;
            g[u].push_back({ v,cost });
        }
    }

    visited[1] = true;
    dfs(1, 0); 
    fill(visited, visited + 100001, false); 
    d = 0; 
    visited[firstArrival] = true;
    dfs(firstArrival, 0); 
    cout << d;
}