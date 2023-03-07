#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int x1, y1;
int x2, y2 = 0;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;

    x1 = wallpaper.size();
    y1 = wallpaper[0].size();

    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[0].size(); j++) {
            if (wallpaper[i][j] == '#') {
                x1 = min(i, x1);
                y1 = min(j, y1);
                x2 = max(i, x2);
                y2 = max(j, y2);
            }
        }
    }

    answer.push_back(x1);
    answer.push_back(y1);
    answer.push_back(x2 + 1);
    answer.push_back(y2 + 1);

    return answer;
}