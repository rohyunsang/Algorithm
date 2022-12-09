#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    for (int i = 0; i < s.size(); i++)
        answer.push_back(-1);

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j])
                answer[j] = j - i;
        }
    }

    return answer;
}