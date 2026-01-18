#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> edges;
    edges.reserve(m);

    for (int i = 0; i < m; i++)
    {
        int st, en, cost;
        cin >> st >> en >> cost;
        edges.push_back({ st, { en, cost }});
    }

    const long long INF = 987654321;
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        bool updated = false;

        for (int j = 0; j < m; j++)
        {
            int st = edges[j].first;
            int en = edges[j].second.first;
            int cost = edges[j].second.second;

            if (dist[st] == INF) continue;

            if (dist[st] + cost < dist[en])
            {
                dist[en] = dist[st] + cost;
                updated = true;
            }
        }

        if (!updated) break;
    }

    for (int j = 0; j < m; j++)
    {
        int st = edges[j].first;
        int en = edges[j].second.first;
        int cost = edges[j].second.second;

        if (dist[st] == INF) continue;

        if (dist[st] + cost < dist[en])
        {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}
