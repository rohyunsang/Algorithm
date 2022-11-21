#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

vector<int> num;
vector<string> oper;

int solution(string s) {
    int answer = 0;
    stringstream ss(s);
    string sTmp;
    while (ss >> sTmp) {
        if (sTmp == "+" || sTmp == "-") {
            oper.push_back(sTmp);
        }
        else
            num.push_back(stoi(sTmp));
    }

    answer = num[0];

    for (int i = 0; i < oper.size(); i++) {
        if (oper[i] == "+")
            answer += num[i + 1];
        else if (oper[i] == "-")
            answer -= num[i + 1];
    }

    return answer;

}