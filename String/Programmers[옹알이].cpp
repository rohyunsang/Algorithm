#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// aya ye woo ma 

vector<string> v;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for (int i = 0; i < babbling.size(); i++) {
        bool check = false;

        for (int j = 0; j < babbling[i].size(); j++) {
            if (babbling[i].substr(j, 3) == "aya") j += 2;
            else if (babbling[i].substr(j, 2) == "ye") j += 1;
            else if (babbling[i].substr(j, 3) == "woo") j += 2;
            else if (babbling[i].substr(j, 2) == "ma") j += 1;
            else {
                check = true;
                break;
            }
        }
        if (!check) answer++;
    }

    return answer;
}
