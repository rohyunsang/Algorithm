#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;

    int d[1025];  // overflow max is m + players(24)
    for (int i = 0; i < 24; i++)
    {
        d[i] = m - 1;
    }

    int playerCnt = (int)players.size();

    for (int i = 0; i < playerCnt; i++)
    {
        while (players[i] > d[i])
        {
            answer++;
            for (int j = 0; j < k; j++)
            {
                d[i + j] += m;
            }
        }
    }



    return answer;
}
