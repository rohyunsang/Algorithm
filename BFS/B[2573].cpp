#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int gragh[301][301] = { 0 };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> gragh[i][j];
        }
    }

    int years = 0;

    while (true)
    {
        // 현재 컴포넌트 수 세기
        bool visited[301][301] = { false };
        int comps = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (gragh[i][j] > 0 && !visited[i][j])
                {
                    comps++;
                    queue<pair<int, int> > q;
                    q.push(pair<int, int>(i, j));
                    visited[i][j] = true;

                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++)
                        {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                            if (gragh[nx][ny] <= 0) continue;
                            if (visited[nx][ny]) continue;
                            visited[nx][ny] = true;
                            q.push(pair<int, int>(nx, ny));
                        }
                    }
                }
            }
        }

        if (comps >= 2)
        {
            cout << years << '\n';
            return 0;
        }
        if (comps == 0)
        {
            cout << 0 << '\n';
            return 0;
        }

        // 
        int dec[301][301] = { 0 };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (gragh[i][j] > 0)
                {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (gragh[nx][ny] == 0) cnt++;
                    }
                    dec[i][j] = cnt;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (gragh[i][j] > 0)
                {
                    int nextH = gragh[i][j] - dec[i][j];
                    if (nextH < 0) nextH = 0;
                    gragh[i][j] = nextH;
                }
            }
        }

        years++;
    }
}
