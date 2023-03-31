#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

bool cmp(vector<string> v, vector<string> v2) {
    if (v[1] < v2[1])
        return true;
    else
        return false;
}

void ConvertToInt() {

}

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), cmp);
    
    

    vector<string> answer;
    return answer;
}

// 스택을 인트로 써야하나 