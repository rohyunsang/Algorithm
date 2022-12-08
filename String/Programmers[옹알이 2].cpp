#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// "aya", "ye", "woo", "ma"

int solution(vector<string> babbling) {
    int answer = 0;
    bool flag = false;
    bool ayaflag = false;
    bool yeflag = false;
    bool wooflag = false;
    bool maflag = false;

    for (int idx = 0; idx < babbling.size(); idx++) {
        for (int i = 0; i < babbling[idx].size(); i++) {
            if (babbling[idx].substr(i, 3) == "aya") {
                i = i + 2;
                flag = true;
                if (ayaflag) {
                    flag = false;
                    break;
                }

                ayaflag = true;

                yeflag = false;
                wooflag = false;
                maflag = false;
            }
            else if (babbling[idx].substr(i, 2) == "ye") {
                i = i + 1;
                flag = true;

                if (yeflag) {
                    flag = false;
                    break;
                }

                yeflag = true;

                ayaflag = false;
                wooflag = false;
                maflag = false;
            }
            else if (babbling[idx].substr(i, 3) == "woo") {
                i = i + 2;
                flag = true;

                if (wooflag) {
                    flag = false;
                    break;
                }
                wooflag = true;

                ayaflag = false;
                yeflag = false;
                maflag = false;
            }
            else if (babbling[idx].substr(i, 2) == "ma") {
                i = i + 1;
                flag = true;

                if (maflag) {
                    flag = false;
                    break;
                }
                maflag = true;

                ayaflag = false;
                yeflag = false;
                wooflag = false;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag)
            answer++;
        flag = false;
        ayaflag = false;
        yeflag = false;
        wooflag = false;
        maflag = false;
    }

    return answer;
}