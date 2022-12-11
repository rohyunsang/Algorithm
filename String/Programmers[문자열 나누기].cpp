#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

/*
"ba na na"	3
"ab ra ca da br a"	6
"aaabbacc ccab ba"	3
*/

using namespace std;

int solution(string s) {
    int answer = 0;
    char cTmp;
    int equalCnt = 0;
    int notEqualCnt = 0;
    bool splitFlag = false;
    cTmp = s[0];
    for (int i = 0; i < s.size(); i++) {
        if (splitFlag) {
            cTmp = s[i];
            splitFlag = false;
            equalCnt = 0;
            notEqualCnt = 0;
        }
        if (cTmp == s[i])
            equalCnt++;
        else {
            notEqualCnt++;
            if (equalCnt == notEqualCnt) {
                answer++;
                splitFlag = true;
            }
        }
    }
    if (!splitFlag && equalCnt)
        answer++;
    
        
    return answer;
}

