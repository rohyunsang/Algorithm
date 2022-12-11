#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

map<char, int> m;


string s[] = { "RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA" };

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    m['R'] = 0; //init
    m['T'] = 0;
    m['F'] = 0;
    m['C'] = 0;
    m['M'] = 0;
    m['J'] = 0;
    m['A'] = 0;
    m['N'] = 0;

    for (int i = 0; i < survey.size(); i++) {
        for (int j = 0; j < 8; j++) {
            if (survey[i] == s[j]) {
                if (choices[i] <= 4) { // 1 -> 3   2 - > 2   3 -> 1 
                    m[s[j][0]] += 4 - choices[i];
                }
                else {
                    m[s[j][1]] += choices[i] - 4; // 5 - > 1 6 - > 2 7 -> 3
                }
                break;
            }
        }
    }

    answer += m['R'] >= m['T'] ? "R" : "T";
    answer += m['C'] >= m['F'] ? "C" : "F";
    answer += m['J'] >= m['M'] ? "J" : "M";
    answer += m['A'] >= m['N'] ? "A" : "N";



    return answer;
}