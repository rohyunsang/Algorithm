#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(int x, int y)
{
    return x > y;
}

vector<int> solution(vector<int> emergency) {
    vector<int> answer;
    vector<int> copy_e;
    map<int, int> m;

    copy_e = emergency;

    sort(copy_e.begin(), copy_e.end(), cmp);

    for (int i = 0; i < copy_e.size(); i++) {
        m[copy_e[i]] = i + 1;
    }

    for (const auto e : emergency) {
        answer.push_back(m[e]);
    }


    return answer;
}