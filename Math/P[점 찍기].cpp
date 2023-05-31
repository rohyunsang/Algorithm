#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;

    for (int i = 0; i <= d; i += k) {
        long long y = sqrt((d * d) - (i * i));
        answer += y / k + 1;
    }




    return answer;
}