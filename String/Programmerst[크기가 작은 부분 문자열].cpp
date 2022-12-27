#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long np = stoll(p);
    int pSize = p.size();

    for (int i = 0; i <= t.size() - pSize; i++) {
        if (stoll(t.substr(i, pSize)) <= np)
            answer++;
    }

    return answer;
}