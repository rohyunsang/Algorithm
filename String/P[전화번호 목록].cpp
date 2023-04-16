#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> p) {

    sort(p.begin(), p.end());

    for (int i = 0; i < p.size() - 1; i++)
    {
        if (p[i] == p[i + 1].substr(0, p[i].size()))
            return false;
    }


    return true;
}