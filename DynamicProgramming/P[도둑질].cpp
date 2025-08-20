#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();

    if (n == 1) return money[0];
    if (n == 2) return max(money[0], money[1]);

    vector<int> dp1(n - 1);
    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);

    for (int i = 2; i < n - 1; i++)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }

    int case1 = dp1[n - 2];  // 첫 번째 포함, 마지막 제외

    vector<int> dp2(n);
    dp2[0] = 0;           // 첫 번째 집 제외
    dp2[1] = money[1];    // 두 번째 집부터 시작

    for (int i = 2; i < n; i++)
    {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    }

    int case2 = dp2[n - 1];  // 첫 번째 제외, 마지막 포함 가능

    return max(case1, case2);
}



// dp 0 1 0 
// dp 1 0 1


// 1 2 3 1 
// o x o x  -> best 



