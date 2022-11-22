#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<char, int> m;

string solution(string s) {
    string answer = "";
    string copys = "";
    copys = s;
    sort(copys.begin(), copys.end());
    copys.erase(unique(copys.begin(), copys.end()), copys.end());
    for (int i = 0; i < copys.size(); i++) {
        m.insert({ copys[i],0 });
    }
    for (int i = 0; i < s.size(); i++) {
        m[s[i]]++;
    }
    for (const auto& m : m) {
        if (m.second == 1)
            answer += m.first;
    }


    return answer;
}