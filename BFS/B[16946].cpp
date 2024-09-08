#include <iostream>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int graph[1001][1001];
bool isVisited[1001][1001];
int setGraph[1001][1001];
int GraphArea[1001][1001];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            graph[i][j] = (int)(s[j] - '0');
        }
    }
    int area = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0 && !isVisited[i][j]) {
                queue<pair<int, int>> q;
                queue<pair<int, int>> save;
                q.push({ i, j });
                isVisited[i][j] = true;
                int cnt = 1;

                while (!q.empty()) {
                    int curX = q.front().first;
                    int curY = q.front().second;
                    q.pop();

                    save.push({ curX, curY });

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = curX + dx[dir];
                        int ny = curY + dy[dir];

                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !isVisited[nx][ny] && graph[nx][ny] == 0) {
                            q.push({ nx, ny });
                            isVisited[nx][ny] = true; 
                            cnt++; 
                        }
                    }
                }

                while (!save.empty()) {
                    int curX = save.front().first;
                    int curY = save.front().second;
                    save.pop();
                    setGraph[curX][curY] = cnt; 
                    GraphArea[curX][curY] = area;
                }
                area++;
            }
        }
    }
    /*
    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << setGraph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << GraphArea[i][j] << " ";
        }
        cout << endl;
    }
    */
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 1) {
                int ans = 0;
                map<int, int> _map;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                    {
                        _map[GraphArea[nx][ny]]++;
                        if (_map[GraphArea[nx][ny]] <= 1) {
                            ans += setGraph[nx][ny];
                        }
                    }
                }
                graph[i][j] = (1 + ans) % 10;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }


    return 0;
}