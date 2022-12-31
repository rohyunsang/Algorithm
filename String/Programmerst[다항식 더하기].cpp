#include <string>
#include <vector>
#include <iostream>
#include <sstream>


using namespace std;
bool addFlag = false;
vector<string> v;

string solution(string polynomial) {
    string answer = "";

    string sTmp = "";
    stringstream stream;
    stream.str(polynomial);
    while (stream >> sTmp)
        v.push_back(sTmp);

    int xNum = 0;
    int Num = 0;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] == "+")
            continue;

        if (v[i] == "x")
            xNum++;
        else if (v[i][1] == 'x' && v[i].size() == 2) {
            xNum += (int)v[i][0] - '0';
        }
        else if (v[i][2] == 'x' && v[i].size() == 3) {
            xNum += ((int)v[i][0] - '0') * 10 + (int)v[i][1] - '0';
        }
        else
            Num += stoi(v[i]);
    }
    if (xNum > 0) {

        if (xNum > 1)
            answer += to_string(xNum);
        answer += 'x';
        if (Num > 0) {
            answer += " + ";
            answer += to_string(Num);
            addFlag = true;
        }
    }

    if (Num > 0 && !addFlag)
        answer += to_string(Num);

    return answer;
}
