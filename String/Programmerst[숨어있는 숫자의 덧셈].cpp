#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    int digitCnt = 0;

    for (int i = 0; i < my_string.size(); i++) {
        for (int j = i; j < my_string.size(); j++) {
            if (isdigit(my_string[j]))
                digitCnt++;
            else
                break;
        }
        if (digitCnt) {
            answer += stoi(my_string.substr(i, digitCnt));
            cout << stoi(my_string.substr(i, digitCnt)) <<" ";
            i += digitCnt - 1;
        }
        
        digitCnt = 0;
    }


    return answer;
}

int main() {

    cout << solution("aAb1B2cC34oOp");

    return 0;
}