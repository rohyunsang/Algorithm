#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int row, col, ans = 0;
char graph[21][21];
map<char, bool> visited;

int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { -1, 0, 0, 1 };

void dfs(int x, int y, int depth) {
    ans = max(ans, depth);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= row || ny >= col)
            continue;
        if (!visited[graph[nx][ny]]) {
            visited[graph[nx][ny]] = true;
            dfs(nx, ny, depth + 1);
            visited[graph[nx][ny]] = false;
        }
    }
}

int main() {
    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        string sTmp;
        cin >> sTmp;
        for (int j = 0; j < col; j++) {
            graph[i][j] = sTmp[j];
        }
    }

    visited[graph[0][0]] = true;
    dfs(0, 0, 1);
    cout << ans;

    return 0;
}