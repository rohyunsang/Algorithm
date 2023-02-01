#include <string>
#include <vector>
#include <sstream>

using namespace std;

string morse[] = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
           ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
           ".--","-..-","-.--","--.." };

string solution(string letter) {
    string answer = "";
    string strTmp = "";
    stringstream ss;
    ss << letter;

    while (ss >> strTmp)
    {
        for (int i = 0; i < 26; i++) {
            if (strTmp == morse[i]) {
                answer += (char)(i + 'a');
            }
        }
    }

    return answer;
}