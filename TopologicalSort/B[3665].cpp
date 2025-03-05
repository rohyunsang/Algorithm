#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;


int t, n, m;
vector<int> degree;
vector<vector<bool>> edges;

int main() {
    cin >> t;
    while (t--) {
        cin >> n;

        degree = vector<int>(n + 1, 0);  
        edges = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false)); 

        vector<int> v;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (auto y : v) {
                edges[x][y] = true;
                degree[y] += 1;
            }
            v.push_back(x);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;

            if (edges[a][b]) {
                edges[a][b] = false;
                degree[b] -= 1;
                edges[b][a] = true;
                degree[a] += 1;
            }
            else if (edges[b][a]) {
                edges[b][a] = false;
                degree[a] -= 1;
                edges[a][b] = true;
                degree[b] += 1;
            }
        }

        queue<int> q;
        bool isCycle = false;

        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            if (q.size() > 1) {
                isCycle = true;
            }

            int cur = q.front();
            ans.push_back(cur);
            q.pop();

            for (int next = 1; next <= n; next++) {
                if (!edges[cur][next]) continue;
                degree[next] -= 1;
                if (degree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (ans.size() != n) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        if (isCycle) {
            cout << "?" << endl;
            continue;
        }

        reverse(ans.begin(), ans.end());

        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}