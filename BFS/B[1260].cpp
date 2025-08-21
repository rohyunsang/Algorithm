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
    {        // �̹� ���ĵǾ� �ִٰ� ����
        if (!visitedDFS[next]) dfs(next);
    }
}

void bfs(int start) {
    queue<int> q;                         // BFS�� queue�� ����
    q.push(start);
    visitedBFS[start] = true;

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        cout << cur << " ";              // ���� ��(�湮 Ȯ�� ����) ���

        for (int next : graph[cur])
        {    // ���ĵ� ���� ����Ʈ�� �״�� ���
            if (!visitedBFS[next])
            {
                visitedBFS[next] = true; // �ߺ� Ǫ�� ���� ���� push ������ üũ/ǥ��
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

    // ����ȣ ���� �������͡� �湮�Ϸ��� ���� ����Ʈ�� �� ���� ����
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
