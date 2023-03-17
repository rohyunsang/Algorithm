#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, pair<int, int>>> q;

bool visited[100 + 1][100 + 1] = { false, };
int map[100 + 1][100 + 1] = { 0, };
int n;
int m;
vector<string> copyMap;
int cnt = 0;

void bfs(int startX, int startY) { 
    q.push({ cnt,{ startX,startY } });
    visited[startX][startY];
    
    while (!q.empty())
    {
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (visited[nx][ny])
                continue;
            if (copyMap[nx][ny] == 'D')
                continue;
            q.push({ map[nx][ny]+1,{nx,ny}});
            map[nx][ny] = q.front().first;
            visited[nx][ny] = true;
            

        }
    }
    

}

int solution(vector<string> board) {
    int answer = 0;
    n = board.size();
    m = board[0].size();

    //copy
    for (const auto& b : board)
        copyMap.push_back(b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                bfs(i, j);
                answer = map[i][j];
            }
        }
    }

    if (answer == 0) {
        answer = -1;
    }


    return answer;
}



// R start
// . empty
// D obstacle
// G Goal 
