#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
// "one4seveneight" 1478

map<string, int> m;

int solution(string s) {
    int answer;
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;

    size_t position = 0;
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        while ((position = s.find(iter->first)) != string::npos) {
            s.replace(position, iter->first.size(), to_string(iter->second));
            std::cout << iter->second << " ";
        }
    }
    answer = stoi(s);

    return answer;
}
s = regex_replace(s, regex("zero"), "0"); //next time use