#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Bipartite Graph BFS 

int main() {
    int k;
    cin >> k;
    while (k--)
    {
        int v, e;
        cin >> v >> e;
        vector<vector<int>> graph(v + 1);
        for (int i = 0; i < e; i++)
        {
            int st, en;
            cin >> st >> en;
            graph[st].push_back(en);
            graph[en].push_back(st);
        }
        vector<int> color(v + 1, 0); // init 0

        bool flag = true;
        for (int s = 1; s <= v && flag; s++)
        {
            if (color[s] != 0) continue;   // 이미 방문된 컴포넌트는 스킵

            queue<int> q;
            q.push(s);
            color[s] = 1;  // 집합이 다른 새로운 컴포넌트이기에 1로 배정해도 ㄱㅊ 

            while (!q.empty() && flag)
            {
                int cur = q.front();
                q.pop();

                for (auto next : graph[cur])
                {
                    if (color[next] == 0)
                    {
                        color[next] = -color[cur]; // 반대로 
                        q.push(next);
                    }
                    else
                    {
                        if (color[next] == color[cur])
                        {
                            flag = false; 
                            break;
                        }
                    }
                }
            }
        }

        if (flag == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

