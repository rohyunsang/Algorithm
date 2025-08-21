#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, v;
vector<vector<int>> graph;
vector<bool> visitedDFS;
vector<bool> visitedBFS;

void dfs(int cur) {
    visitedDFS[cur] = true;
    cout << cur << " ";
    for (int next : graph[cur])
    {        // 이미 정렬되어 있다고 가정
        if (!visitedDFS[next]) dfs(next);
    }
}

void bfs(int start) {
    queue<int> q;                         // BFS는 queue가 본질
    q.push(start);
    visitedBFS[start] = true;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << " ";              // 꺼낼 때(방문 확정 시점) 출력

        for (int next : graph[cur])
        {    // 정렬된 인접 리스트를 그대로 사용
            if (!visitedBFS[next])
            {
                visitedBFS[next] = true; // 중복 푸시 방지 위해 push 직전에 체크/표시
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> v;
    graph.assign(n + 1, {});
    visitedDFS.assign(n + 1, false);
    visitedBFS.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // “번호 작은 정점부터” 방문하려면 인접 리스트를 한 번만 정렬
    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    // DFS
    dfs(v);
    cout << "\n";

    // BFS
    bfs(v);
    cout << "\n";

    return 0;
}
