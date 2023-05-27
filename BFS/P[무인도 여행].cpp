#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 101;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visited[MAX][MAX];
vector<int> answer;

void bfs(vector<string> v, int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;

    int result = 0;

    while (!q.empty()) {
        int xTmp = q.front().first;
        int yTmp = q.front().second;
        result += (v[xTmp][yTmp] - '0');
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + xTmp;
            int ny = dy[i] + yTmp;
            if (nx < 0 || ny < 0 || nx >= v.size() || ny >= v[x].size() || visited[nx][ny])
                continue; 
            if (v[nx][ny] != 'X') {
                visited[nx][ny] = true;
                q.push({ nx,ny });
            }
        }
    }
    answer.push_back(result);
}

vector<int> solution(vector<string> maps) {

    for (int i = 0; i < maps.size(); i++) {
        for (int j = 0; j < maps[i].size(); j++) {
            if (maps[i][j] != 'X' && !visited[i][j])
                bfs(maps, i, j);
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.size() == 0)
        answer.push_back(-1);

    return answer;
}