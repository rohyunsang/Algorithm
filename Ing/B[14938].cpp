#include <iostream>
#include <vector>
#include <queue>
#include <cstring> //memset
#include <algorithm>

using namespace std;

vector<pair<int, int>> graph[101];  
int items[101];                   
bool visited[101];                
int n, m, r;

int bfs(int start) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;  
    q.push({ start, 0 });
    visited[start] = true;

    int totalItems = 0;

    while (!q.empty()) {
        int current = q.front().first;
        int distance = q.front().second;
        q.pop();

        totalItems += items[current];

        for (auto& edge : graph[current]) {
            int next = edge.first;
            int nextDistance = distance + edge.second;

            if (!visited[next] && nextDistance <= m) {
                visited[next] = true;   // �׳� �湮������ true ó�� .
                q.push({ next, nextDistance });
            }
        }
    }
    return totalItems;
}

int main() {
    cin >> n >> m >> r;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> items[i];
    }

    for (int i = 0; i < r; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].push_back({ b, cost });
        graph[b].push_back({ a, cost }); // ������̹Ƿ�
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, bfs(i));
    }

    cout << ans << endl;
    return 0;
}