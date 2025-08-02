#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int answer = 0;

// 방향 상수
enum { LEFT = 0, RIGHT, UP, DOWN };

void moveLeft(vector<vector<int>>& a) {
    for (int i = 0; i < N; i++)
    {
        vector<int> line;
        for (int j = 0; j < N; j++)
            if (a[i][j]) line.push_back(a[i][j]);

        vector<int> merged;
        for (int k = 0; k < (int)line.size(); )
        {
            if (k + 1 < (int)line.size() && line[k] == line[k + 1])
            {
                merged.push_back(line[k] * 2);
                answer = max(answer, line[k] * 2);
                k += 2;
            }
            else
            {
                merged.push_back(line[k]);
                k++;
            }
        }
        merged.resize(N, 0);
        for (int j = 0; j < N; j++)
            a[i][j] = merged[j];
    }
}

void moveRight(vector<vector<int>>& a) {
    for (int i = 0; i < N; i++)
    {
        vector<int> line;
        for (int j = N - 1; j >= 0; j--)
            if (a[i][j]) line.push_back(a[i][j]);

        vector<int> merged;
        for (int k = 0; k < (int)line.size(); )
        {
            if (k + 1 < (int)line.size() && line[k] == line[k + 1])
            {
                merged.push_back(line[k] * 2);
                answer = max(answer, line[k] * 2);
                k += 2;
            }
            else
            {
                merged.push_back(line[k]);
                k++;
            }
        }
        merged.resize(N, 0);
        for (int j = N - 1, idx = 0; j >= 0; j--, idx++)
            a[i][j] = merged[idx];
    }
}

void moveUp(vector<vector<int>>& a) {
    for (int j = 0; j < N; j++)
    {
        vector<int> line;
        for (int i = 0; i < N; i++)
            if (a[i][j]) line.push_back(a[i][j]);

        vector<int> merged;
        for (int k = 0; k < (int)line.size(); )
        {
            if (k + 1 < (int)line.size() && line[k] == line[k + 1])
            {
                merged.push_back(line[k] * 2);
                answer = max(answer, line[k] * 2);
                k += 2;
            }
            else
            {
                merged.push_back(line[k]);
                k++;
            }
        }
        merged.resize(N, 0);
        for (int i = 0; i < N; i++)
            a[i][j] = merged[i];
    }
}

void moveDown(vector<vector<int>>& a) {
    for (int j = 0; j < N; j++)
    {
        vector<int> line;
        for (int i = N - 1; i >= 0; i--)
            if (a[i][j]) line.push_back(a[i][j]);

        vector<int> merged;
        for (int k = 0; k < (int)line.size(); )
        {
            if (k + 1 < (int)line.size() && line[k] == line[k + 1])
            {
                merged.push_back(line[k] * 2);
                answer = max(answer, line[k] * 2);
                k += 2;
            }
            else
            {
                merged.push_back(line[k]);
                k++;
            }
        }
        merged.resize(N, 0);
        for (int i = N - 1, idx = 0; i >= 0; i--, idx++)
            a[i][j] = merged[idx];
    }
}

void dfs(int depth, vector<vector<int>> board) {


    for (auto& row : board)
        for (int v : row)
            answer = max(answer, v);

    if (depth == 5) return;

    for (int dir = 0; dir < 4; dir++)
    {
        auto next = board;
        if (dir == LEFT)  moveLeft(next);
        if (dir == RIGHT) moveRight(next);
        if (dir == UP)    moveUp(next);
        if (dir == DOWN)  moveDown(next);
        dfs(depth + 1, next);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    dfs(0, board);
    cout << answer << "\n";
    return 0;
}
