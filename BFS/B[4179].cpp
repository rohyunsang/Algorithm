#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int grid[1001][1001];          // -1: 벽, 0: 빈칸
bool visited[1001][1001];
int fireTime[1001][1001];      // 불
int distJ[1001][1001];         // 지훈

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin >> row >> col;

    pair<int, int> startPoint = make_pair(-1, -1);
    queue<pair<int, int> > fq;  

    // 초기화
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            grid[i][j] = 0;
            visited[i][j] = false;
            fireTime[i][j] = -1;
            distJ[i][j] = -1;
        }
    }

    for (int i = 0; i < row; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < col; j++)
        {
            if (s[j] == '#')
            {
                grid[i][j] = -1; 
            }
            else if (s[j] == 'J')
            {
                startPoint = make_pair(i, j);
                grid[i][j] = 0;  
            }
            else if (s[j] == '.')
            {
                grid[i][j] = 0;  
            }
            else if (s[j] == 'F')
            {
                grid[i][j] = 0;      
                fireTime[i][j] = 0;  
                fq.push(make_pair(i, j));
            }
        }
    }


    while (!fq.empty())
    {
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if (grid[nx][ny] == -1) continue;     
            if (fireTime[nx][ny] != -1) continue; 
            fireTime[nx][ny] = fireTime[x][y] + 1;
            fq.push(make_pair(nx, ny));
        }
    }

    queue<pair<int, int> > q;
    int sx = startPoint.first, sy = startPoint.second;
    distJ[sx][sy] = 0;
    visited[sx][sy] = true;
    q.push(make_pair(sx, sy));

    if (sx == 0 || sx == row - 1 || sy == 0 || sy == col - 1)
    {
        cout << 1 << "\n";
        return 0;
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if (grid[nx][ny] == -1) continue;    
            if (visited[nx][ny]) continue;

            int nt = distJ[x][y] + 1;            
            
            if (fireTime[nx][ny] != -1 && fireTime[nx][ny] <= nt) continue;

            visited[nx][ny] = true;
            distJ[nx][ny] = nt;

            if (nx == 0 || nx == row - 1 || ny == 0 || ny == col - 1)
            {
                cout << nt + 1 << "\n";           
                return 0;
            }
            q.push(make_pair(nx, ny));
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}


// 불 먼저 bfs 해야하는데 사람 먼저 bfs 해버림. 