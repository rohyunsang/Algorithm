#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<int> d(n + 1, -1);
    queue<int> q;
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < edge.size(); i++) {
        int x = edge[i][0];
        int y = edge[i][1];

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    d[1] = 0;

    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if (d[next] == -1) { // 가보지 않은 상태라면 
                d[next] = d[cur] + 1;
                q.push(next);
            }
        }
    }

    int max = 0;
    for (int i = 0; i < d.size(); i++) {
        if (max < d[i]) max = d[i];
    }

    for (int i = 0; i < d.size(); i++)
    {
        if (d[i] == max)
        {
            answer++;
        }
    }

    return answer;
}