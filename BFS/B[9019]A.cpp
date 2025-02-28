#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void bfs(int a, int b) {
    vector<bool> visit(10000, false);
    vector<string> ans(10000);
    queue<int> q;

    visit[a] = true;
    q.push(a);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == b)
        {
            cout << ans[b] << "\n";
            return;
        }

        // case 1
        int nx = (x * 2) % 10000;
        if (!visit[nx])
        {
            visit[nx] = true;
            q.push(nx);
            ans[nx] = ans[x] + "D";
        }

        // case 2
        nx = (x == 0) ? 9999 : x - 1;
        if (!visit[nx])
        {
            visit[nx] = true;
            q.push(nx);
            ans[nx] = ans[x] + "S";
        }

        // case 3
        nx = (x % 1000) * 10 + (x / 1000);
        if (!visit[nx])
        {
            visit[nx] = true;
            q.push(nx);
            ans[nx] = ans[x] + "L";
        }

        // case 4
        nx = (x / 10) + (x % 10) * 1000;
        if (!visit[nx])
        {
            visit[nx] = true;
            q.push(nx);
            ans[nx] = ans[x] + "R";
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        bfs(a, b);
    }
    return 0;
}
