#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> v;

string solution(string s) {
    string answer = "";
    int cnt = 0;
    string sTmp = "";
    stringstream ss;
    ss << s;
    while (ss >> sTmp)
        v.push_back(stoi(sTmp));
    for (const auto v : v)
        cout << v << " ";
    
    sort(v.begin(), v.end());

    answer += to_string(v.front());
    answer += " ";
    answer += to_string(v.back());

    return answer;
}