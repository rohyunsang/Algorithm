#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
    if (p1.second == p2.second)
        return p1.first > p2.first;
    return p1.second > p2.second;
}


int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int idx = 0;

    map<int, int> m;

    sort(tangerine.begin(), tangerine.end());

    for (const auto& t : tangerine) {
        m[t]++;
    }
    vector<pair<int, int>> cntV(m.begin(), m.end());

    sort(cntV.begin(), cntV.end(), cmp);

    while (k > 0) {
        if (k <= cntV[idx].second) {
            answer++;
            break;
        }
        else {
            answer++;
            k -= cntV[idx].second;
        }
        idx++;
    }



    return answer;
}