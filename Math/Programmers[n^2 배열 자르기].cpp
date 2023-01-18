#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1 2 3 4
// 2 2 3 4 
// 3 3 3 4 
// 4 4 4 4 
// i행 j열의 값은 i j 중 더 큰 값에 + 1을 한 값이다.


vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++) {
        int row = i / n;
        int col = i % n;
        answer.push_back(max(row, col) + 1);
    }


    return answer;
}