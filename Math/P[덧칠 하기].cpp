#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int cur = 0;
    for (const auto s : section) {
        if (s > cur) {
            answer++;
            cur = s + m - 1;
        }
    }


    return answer;
}