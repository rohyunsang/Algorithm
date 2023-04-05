#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

// x point -4.5 ~ 4.5 
// y point -4.5 ~ 4.5

int solution(string dirs) {
    int answer = 0;
    vector<pair<int, int>> v;
    set<pair<float, float>> s;
    v.push_back({ 0,0 });

    

    for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i] == 'U')
        {
            if (v[0].second >= 5)
                continue;
            s.insert({ v[0].first,v[0].second + 0.5 });
            v[0].second++;
        }
        else if (dirs[i] == 'D')
        {
            if (v[0].second <= -5)
                continue;
            s.insert({ v[0].first,v[0].second - 0.5 });
            v[0].second--;
        }
        else if (dirs[i] == 'R')
        {
            if (v[0].first >= 5)
                continue;
            s.insert({ v[0].first + 0.5,v[0].second });
            v[0].first++;
        }
        else if (dirs[i] == 'L')
        {
            if (v[0].first <= -5)
                continue;
            s.insert({ v[0].first - 0.5,v[0].second });
            v[0].first--;
        }
    }

    

    answer = s.size();

    return answer;
}