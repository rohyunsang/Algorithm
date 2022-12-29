#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) {
        return p1.first > p2.first;
    }
    return p1.second < p2.second;
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    vector<pair<int, int>> m;

    for (int i = 0; i < numlist.size(); i++) {
        m.push_back({ numlist[i], abs(numlist[i] - n) });
    }

    sort(m.begin(), m.end(), cmp);

    for (const auto m : m) {
        answer.push_back(m.first);
    }


    return answer;
}