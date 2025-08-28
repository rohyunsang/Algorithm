#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dist[10001];
int cnt[10001];
bool visited[10001];

int n;
int s, e;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> dist[i];
    }

    cin >> s >> e;

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == e) break;

        // 현재 위치부터 배수로 BFS
        for (int i = cur + dist[cur]; i <= n; i += dist[cur])
        {
            if (visited[i]) continue;
            visited[i] = true;
            cnt[i] = cnt[cur] + 1;
            q.push(i);
        }

        // 현재 위치부터 음의 배수로 BFS 
        for (int i = cur - dist[cur]; i >= 1; i -= dist[cur])
        {
            if (visited[i]) continue;
            visited[i] = true;
            cnt[i] = cnt[cur] + 1;
            q.push(i);
        }
    }

    if (cnt[e] == 0) cout << -1;
    else cout << cnt[e];

    return 0; 
}