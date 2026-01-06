#include <iostream>
using namespace std;

char map[64][64];

void dfs(int x, int y, int size)
{
    char cur = map[x][y];
    bool same = true;

    for (int dx = 0; dx < size; dx++)
    {
        for (int dy = 0; dy < size; dy++)
        {
            if (cur != map[x + dx][y + dy])
            {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same)
    {
        cout << cur;
    }
    else
    {
        int half = size / 2;
        cout << "(";
        dfs(x, y, half);                 
        dfs(x, y + half, half);          
        dfs(x + half, y, half);          
        dfs(x + half, y + half, half);   
        cout << ")";
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0, 0, n);
    return 0;
}
