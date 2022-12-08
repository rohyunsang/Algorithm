#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> sv;

    for (const auto& s : strings) {
        sv.push_back({ s[n],s });
    }

    sort(sv.begin(), sv.end());
    for (const auto& sv : sv) {
        answer.push_back(sv.second);
    }

    return answer;
}