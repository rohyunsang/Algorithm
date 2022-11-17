#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(vector<string> quiz) {

    vector<string> answer;
    string rE; //rightExpression
    string lE; //leftExpression

    string RN; //rightExpression rightnum;
    string LN; //rightExpression leftnum;


    bool isAdd = false;
    for (int t = 0; t < quiz.size(); t++) {
        for (int i = 0; i < quiz[t].size() - 1; i++) {
            if (quiz[t][i] == '=') {
                rE = quiz[t].substr(0, i - 1); // 공백제외 왼쪽
                lE = quiz[t].substr(i + 2, quiz[t].size() - i); // 공백제외 오른쪽
                break;
            }

        }

        for (int i = 2; i < rE.size() - 1; i++) {
            if (rE[i] == '+')
            {
                RN = rE.substr(0, i - 1);
                LN = rE.substr(i + 2, rE.size() - i);
                isAdd = true;
                break;
            }
            if (rE[i] == '-')
            {
                RN = rE.substr(0, i - 1);
                LN = rE.substr(i + 2, rE.size() - i);
                isAdd = false;
                break;
            }
        }
        int RNToInt = stoi(RN);
        int LNToInt = stoi(LN);
        int lEToInt = stoi(lE);

        if (isAdd) {
            if (RNToInt + LNToInt == lEToInt)
                answer.push_back("O");
            else
                answer.push_back("X");
        }
        else {
            if (RNToInt - LNToInt == lEToInt)
                answer.push_back("O");
            else
                answer.push_back("X");
        }

        rE = ""; //rightExpression Init
        lE = ""; //leftExpression Init

        RN = ""; //rightExpression rightnum; Init
        LN = ""; //rightExpression leftnum; Init

        RNToInt = 0;
        LNToInt = 0;
        lEToInt = 0;

        isAdd = false;

    }


    return answer;
}