#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX 1001
#define INF 987654321

vector<vector<pair<int, int>>> v(MAX);
vector<int> d(MAX);
vector<int> prevNode(MAX, -1); 

int main() {

    int n, m, startP, endP;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        v[x].push_back({ y, cost });
    }

    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    cin >> startP >> endP;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, startP });
    d[startP] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > d[cur]) continue;

        for (auto& edge : v[cur]) {
            int next = edge.first;
            int nextCost = edge.second;

            if (d[cur] + nextCost < d[next]) {
                d[next] = d[cur] + nextCost;
                prevNode[next] = cur; // 이전 노드를 저장
                pq.push({ d[next], next });
            }
        }
    }

    cout << d[endP] << endl;

    stack<int> path;
    int node = endP;
    while (node != -1) {
        path.push(node);
        node = prevNode[node];
    }

    cout << path.size() << endl;
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }

    return 0;
}