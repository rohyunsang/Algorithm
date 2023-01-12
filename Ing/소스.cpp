#include <string>
#include <vector>
#include <map>

using namespace std;

int check(map<string, int> m, vector<string> discount, int idx) {
    for (int i = idx; i < (idx + 10); i++)
    {
        if (!m[discount[i]])
            return 0;
        m[discount[i]]--;
    }

    return 1;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;

    for (int i = 0; i < number.size(); i++) {
        m[want[i]] = number[i];
    }

    for (int i = 0; i < discount.size() - 9; i++) {
        answer += check(m, discount, i);
    }

    return answer;
}