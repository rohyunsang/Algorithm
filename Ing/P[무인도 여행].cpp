#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool visit[101][101];

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    for (int x = 0; x < maps.size(); x++)
    {
        for (int y = 0; y < maps[x].size(); y++)
        {
            if (maps[x][y] == 'X' || visit[x][y])
            {
                continue;
            }

            queue<pair<int, int>> q;
            q.push({ x, y });
            visit[x][y] = true;
            int sum = maps[x][y] - '0';

            while (!q.empty())
            {
                int y = q.front().first;
                int x = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (ny < 0 || ny >= maps.size() || nx < 0 || nx >= maps[0].size())
                        continue;
                    
                    if (visit[nx][ny] || maps[nx][ny] == 'X')
                        continue;

                    visit[nx][ny] = true;
                    sum += maps[nx][ny] - '0';

                    q.push({ nx, ny });
                }
            }

            answer.push_back(sum);
        }
    }

    sort(answer.begin(), answer.end());

    if (answer.empty())
    {
        answer.push_back(-1);
    }

    return answer;
}
