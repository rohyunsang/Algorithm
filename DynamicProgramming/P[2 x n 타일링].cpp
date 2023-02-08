#include <string>
#include <vector>

using namespace std;

//Dynamic Programming 

// 1
// 2
// 3
// 5
// 8


int solution(int n) {
    int answer = 0;

    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    for (int i = 2; i < n; i++) {
        v.push_back((v[i - 2] + v[i - 1]) % 1000000007);
    }
    answer = v.back();

    return answer;
}