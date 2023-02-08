#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// x point -4.5 ~ 4.5 
// y point -4.5 ~ 4.5

int solution(string dirs) {
    int answer = 0;
    vector<pair<int, int>> v;
    v.push_back({ 0,0 });

    vector<pair<float, float>> fv;

    for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == 'U')
        {
            if (v[0].second >= 5)
                continue;
            fv.push_back({ v[0].first,v[0].second + 0.5 });
            v[0].second++;
        }
        else if (dirs[i] == 'D')
        {
            if (v[0].second <= -5)
                continue;
            fv.push_back({ v[0].first,v[0].second - 0.5 });
            v[0].second--;
        }
        else if (dirs[i] == 'R')
        {
            if (v[0].first >= 5)
                continue;
            fv.push_back({ v[0].first + 0.5,v[0].second });
            v[0].first++;
        }
        else if (dirs[i] == 'L')
        {
            if (v[0].first <= -5)
                continue;
            fv.push_back({ v[0].first - 0.5,v[0].second });
            v[0].first--;
        }
    }

    sort(fv.begin(), fv.end());
    fv.erase(unique(fv.begin(), fv.end()), fv.end());

    for (const auto fv : fv)
        cout << fv.first << " ";

    answer = fv.size();

    return answer;
}