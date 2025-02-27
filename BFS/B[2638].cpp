#include <iostream>
#include <vector>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int cheeseCount;
int n, m;
vector<vector<int>> map;
vector<vector<bool>> OutDoorAir;

bool boundary(int x, int y) {
    if (0 <= x && x < n && 0 <= y && y < m) return true;

    return false;
}

void FindDoorAir(int x, int y) {

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (boundary(nx, ny))
        {
            if (map[nx][ny] == 0 && OutDoorAir[nx][ny] == false)
            {
                OutDoorAir[nx][ny] = true;
                FindDoorAir(nx, ny);
            }
        }
    }
}

void CheeseCheck() {
    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < m; b++)
        {
            if (map[a][b] == 1)
            {
                int outAirCnt = 0;
                for (int i = 0; i < 4; i++)
                {
                    int nx = a + dx[i];
                    int ny = b + dy[i];
                    if (boundary(nx, ny))
                    {
                        if (OutDoorAir[nx][ny] == true)
                        {
                            outAirCnt++;
                        }
                    }

                }
                if (outAirCnt >= 2)
                {
                    map[a][b] = 0;
                    cheeseCount--;
                }
            }
        }
    }
}






int main() {

    cin >> n >> m;
    map.resize(n, vector<int>(m, 0));


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 1) cheeseCount++;
        }
    }

    int ans = 0;
    while (cheeseCount > 0)
    {
        OutDoorAir.assign(n, vector<bool>(m, false));
        OutDoorAir[0][0] = true;
        FindDoorAir(0, 0);
        CheeseCheck();

        ans++;
    }

    cout << ans << '\n';

    return 0;
}