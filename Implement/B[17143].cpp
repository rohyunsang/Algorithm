#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, M;

struct Shark
{
    int r, c, s, d, z;  
    bool alive;
};

vector<Shark> sharks;
vector<vector<int>> board; 


int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, 1, -1 };

void moveSharks()
{
    board.assign(R + 1, vector<int>(C + 1, -1));

    for (int i = 0; i < M; i++)
    {
        if (!sharks[i].alive) continue;

        int r = sharks[i].r;
        int c = sharks[i].c;
        int s = sharks[i].s;
        int d = sharks[i].d;

        // move optimization !! ! ! ! ! !
        if (d == 1 || d == 2) s %= (2 * (R - 1));
        else s %= (2 * (C - 1));

        for (int k = 0; k < s; k++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 1 || nr > R || nc < 1 || nc > C)
            {
                if (d == 1) d = 2;
                else if (d == 2) d = 1;
                else if (d == 3) d = 4;
                else if (d == 4) d = 3;

                nr = r + dr[d];
                nc = c + dc[d];
            }
            r = nr;
            c = nc;
        }

        sharks[i].r = r;
        sharks[i].c = c;
        sharks[i].d = d;
    }

    for (int i = 0; i < M; i++)
    {
        if (!sharks[i].alive) continue;

        int r = sharks[i].r;
        int c = sharks[i].c;

        if (board[r][c] == -1)
        {
            board[r][c] = i;
        }
        else
        {
            int other = board[r][c];
            if (sharks[other].z > sharks[i].z)
            {
                sharks[i].alive = false;
            }
            else
            {
                sharks[other].alive = false;
                board[r][c] = i;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> M;

    sharks.resize(M);
    board.assign(R + 1, vector<int>(C + 1, -1));

    for (int i = 0; i < M; i++)
    {
        cin >> sharks[i].r >> sharks[i].c >> sharks[i].s >> sharks[i].d >> sharks[i].z;
        sharks[i].alive = true;
        board[sharks[i].r][sharks[i].c] = i;
    }

    int ans = 0;

    for (int fisher = 1; fisher <= C; fisher++)
    {

        for (int r = 1; r <= R; r++)
        {
            int idx = board[r][fisher];
            if (idx != -1 && sharks[idx].alive)
            {
                sharks[idx].alive = false;
                ans += sharks[idx].z;
                board[r][fisher] = -1;
                break;
            }
        }

        moveSharks();
    }

    cout << ans;
    return 0;
}
