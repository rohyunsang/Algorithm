#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 1 is »§
// 2 is ¾ßÃ¤
// 3 is °í±â 

int solution(vector<int> ingredient) {
    int answer = 0;
    string stringStack = "";

    for (int i = 0; i < ingredient.size(); i++) {
        stringStack += to_string(ingredient[i]);
        int len = stringStack.size();
        if (len >= 4) {
            int idx = len - 4;
            string sTmp = stringStack.substr(idx);
            if (sTmp == "1231") {
                stringStack = stringStack.substr(0, idx);
                answer++;
            }
        }
    }


    return answer;
}