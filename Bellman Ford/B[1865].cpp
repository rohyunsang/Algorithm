#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
    int from, to, cost;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    while (TC--)
    {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;

        // 도로 (양방향)
        for (int i = 0; i < M; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({ s, e, t });
            edges.push_back({ e, s, t });
        }

        for (int i = 0; i < W; i++)
        {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({ s, e, -t });
        }

        vector<int> dist(N + 1, 0);

        bool negativeCycle = false;

        for (int i = 1; i <= N; i++)
        {
            for (auto& edge : edges)
            {
                if (dist[edge.to] > dist[edge.from] + edge.cost)
                {
                    dist[edge.to] = dist[edge.from] + edge.cost;
                    if (i == N)
                    {
                        negativeCycle = true;
                        break;
                    }
                }
            }
            if (negativeCycle) break;
        }
        cout << (negativeCycle ? "YES\n" : "NO\n");
    }

    return 0;
}
