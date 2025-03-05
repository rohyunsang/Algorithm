#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
char map[100][100];
int cnt[100][100] = { 0 };
bool visit[100][100] = { 0 };
int W, H;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });

    while (!q.empty()) {
        int _x = q.front().first;
        int _y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = _x + dx[i];
            int ny = _y + dy[i];
            while (nx >= 0 && ny >= 0 && nx < H && ny < W && map[nx][ny] != '*') {
                if (cnt[nx][ny] == 0) {
                    cnt[nx][ny] = cnt[_x][_y] + 1;
                    q.push({ nx, ny });
                }
                // 아래 부분이 기존 bfs와 다르게, 계속 벽을 만날때까지 이동한다. 
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
}

int main() {
    cin >> W >> H;

    vector<pair<int, int>> v;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'C') v.push_back({ i,j });
        }
    }

    bfs(v[0].first, v[0].second);

    cout << cnt[v[1].first][v[1].second] - 1 << endl;

    return 0;
}