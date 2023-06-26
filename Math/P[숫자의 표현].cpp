#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    // 1 2 3 4 5 6 ~
    // 2 3 4 5 ~
    // 3 4 5 ~ 

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = i; j <= n; j++) {
            sum += j;
            if (sum > n)
                break;
            if (sum == n) {
                answer++;
                break;
            }
            //cout << "sum" << " " << sum;
        }
        //cout << endl;
    }

    return answer;
}
