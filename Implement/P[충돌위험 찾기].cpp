#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// 시간별 좌표를 기록하는 해시맵
unordered_map<int, unordered_map<int, unordered_map<int, int>>> map;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    for (int i = 0; i < routes.size(); i++)
    {
        int t = 0;
        for (int j = 0; j < routes[i].size() - 1; j++)
        {
            // 현재 위치
            int curX = points[routes[i][j] - 1][0];
            int curY = points[routes[i][j] - 1][1];
            // 목표 위치
            int targetX = points[routes[i][j + 1] - 1][0];
            int targetY = points[routes[i][j + 1] - 1][1];

            if (j == 0)
            {
                map[curX][curY][t]++;
                t++;
            }

            // X축 이동 (우선순위 높음)
            while (curX != targetX)
            {
                curX += (curX < targetX) ? 1 : -1;
                map[curX][curY][t]++; // 해당 시간대에 좌표 방문 횟수 증가
                t++;
            }

            // Y축 이동
            while (curY != targetY)
            {
                curY += (curY < targetY) ? 1 : -1;
                map[curX][curY][t]++;
                t++;
            }
        }
    }

    // 충돌 횟수 계산 (2대 이상 로봇이 동일 좌표에 있으면 위험 상황)
    for (auto& x : map)
    {
        for (auto& y : x.second)
        {
            for (auto& t : y.second)
            {
                if (t.second > 1)
                { // 2대 이상 존재할 때 충돌 발생
                    answer += 1;
                }
            }
        }
    }

    return answer;
}