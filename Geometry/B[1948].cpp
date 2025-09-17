#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> g(n + 1);
    vector<vector<pair<int, int>>> rg(n + 1);
    vector<int> degree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        g[a].push_back({ b, t });
        rg[b].push_back({ a, t });
        degree[b]++;
    }

    int st, en;
    cin >> st >> en;

    vector<int> dist(n + 1, 0);
    queue<int> q;

    q.push(st);

    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int i = 0; i < (int)g[cur].size(); i++)
        {
            int nxt = g[cur][i].first;
            int w = g[cur][i].second;
            if (dist[nxt] < dist[cur] + w)
            {
                dist[nxt] = dist[cur] + w;
            }
            degree[nxt]--;
            if (degree[nxt] == 0) q.push(nxt);
        }
    }

    
    //  
    cout << dist[en] << "\n";

    // 
    vector<int> visited(n + 1, 0);
    queue<int> rq;
    rq.push(en);
    visited[en] = 1;

    int critical_edges = 0;

    while (!rq.empty())
    {
        int cur = rq.front(); rq.pop();
        for (int i = 0; i < (int)rg[cur].size(); i++)
        {
            int prev = rg[cur][i].first;
            int w = rg[cur][i].second;
            // Á¶°Ç: dist[cur] == dist[prev] + w 
            if (dist[cur] == dist[prev] + w)
            {
                critical_edges++;
                if (!visited[prev])
                {
                    visited[prev] = 1;
                    rq.push(prev);
                }
            }
        }
    }

    cout << critical_edges << "\n";
    return 0;
}
