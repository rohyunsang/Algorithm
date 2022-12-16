#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> check(n, 1);  //vector init
    for (auto l : lost)        check[l - 1]--;
    for (auto r : reserve)        check[r - 1]++;
    for (size_t i = 0; i < check.size(); i++) {
        if (!check[i]) {
            if (i != check.size() - 1 && check[i + 1] == 2) {
                check[i + 1]--;
                check[i]++;
            }
            else if (i && check[i - 1] == 2) {
                check[i - 1]--;
                check[i]++;
            }
        }
    }
    for (auto a : check)
        if (a != 0)    answer++;
    return answer;
}