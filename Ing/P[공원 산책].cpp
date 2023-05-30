#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

pair<int, int> startPoint;
bool breakFlag = false;

// N  0,  1
// S  0, -1
// W  -1, 0
// E  1,  0

pair<int, int> moving[4] = { {0,1},{0,-1},{-1,0},{1,0} };
map<char, int> m = { {'N',0},{'S',1},{'W',2},{'E',3} };

void MovingRobotPuppy(pair<int,int> startPoint,string route) {

}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;

    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[0].size(); j++) {
            if (park[i][j] == 'S')
            {
                startPoint = { i,j };
                breakFlag = true;
                break;
            }
        }
        if (breakFlag) break;
    }
    for (auto route : routes) {
        char op = m[route[0]];
        int n = route[2] - '0';

        int nx = startPoint.first;
        int ny = startPoint.second;

        while (n--) {
            nx += moving[op].first;
            ny += moving[op].second;

            if ((nx < 0 || park.size() <= nx || ny < 0 || park[0].size() <= ny) || park[nx][ny] == 'X')
                break;
        }

        if (n < 0) startPoint = { nx, ny }; 
    }
    answer.push_back(startPoint.first);
    answer.push_back(startPoint.second);

    return answer;
}
