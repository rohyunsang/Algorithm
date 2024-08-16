#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool isVisited[101][101] = { false, };

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

vector<int> answer;

int row;
int col;

void bfs(int x, int y, const vector<string> maps) {
    int result = 0;
    queue<pair<int, int>> q;
    q.push({ x,y });
    isVisited[x][y] = true;

    while (!q.empty()) {
        int _x = q.front().first;
        int _y = q.front().second;

        result += (int)maps[_x][_y] - '0';
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = _x + dx[i];
            int ny = _y + dy[i];

            if (nx < 0 || ny < 0 || nx >= row || ny >= col)
                continue;
            if (isVisited[nx][ny] || maps[nx][ny] == 'X')
                continue;

            q.push({ nx,ny });
            isVisited[nx][ny] = true;
        }
    }

    answer.push_back(result);
}


vector<int> solution(vector<string> maps) {
    row = maps.size();
    col = maps[0].size();

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] == 'X') continue;
            if (isVisited[i][j]) continue;
            bfs(i, j, maps);
        }
    }



    sort(answer.begin(), answer.end());

    if (answer.empty())
        answer.push_back(-1);

    return answer;
}