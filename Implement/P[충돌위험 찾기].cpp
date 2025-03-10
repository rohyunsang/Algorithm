#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

// �ð��� ��ǥ�� ����ϴ� �ؽø�
unordered_map<int, unordered_map<int, unordered_map<int, int>>> map;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    for (int i = 0; i < routes.size(); i++)
    {
        int t = 0;
        for (int j = 0; j < routes[i].size() - 1; j++)
        {
            // ���� ��ġ
            int curX = points[routes[i][j] - 1][0];
            int curY = points[routes[i][j] - 1][1];
            // ��ǥ ��ġ
            int targetX = points[routes[i][j + 1] - 1][0];
            int targetY = points[routes[i][j + 1] - 1][1];

            if (j == 0)
            {
                map[curX][curY][t]++;
                t++;
            }

            // X�� �̵� (�켱���� ����)
            while (curX != targetX)
            {
                curX += (curX < targetX) ? 1 : -1;
                map[curX][curY][t]++; // �ش� �ð��뿡 ��ǥ �湮 Ƚ�� ����
                t++;
            }

            // Y�� �̵�
            while (curY != targetY)
            {
                curY += (curY < targetY) ? 1 : -1;
                map[curX][curY][t]++;
                t++;
            }
        }
    }

    // �浹 Ƚ�� ��� (2�� �̻� �κ��� ���� ��ǥ�� ������ ���� ��Ȳ)
    for (auto& x : map)
    {
        for (auto& y : x.second)
        {
            for (auto& t : y.second)
            {
                if (t.second > 1)
                { // 2�� �̻� ������ �� �浹 �߻�
                    answer += 1;
                }
            }
        }
    }

    return answer;
}