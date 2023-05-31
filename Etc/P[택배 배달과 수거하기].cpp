#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int del = 0;
int pic = 0;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    reverse(deliveries.begin(), deliveries.end());
    reverse(pickups.begin(), pickups.end());

    for (int i = 0; i < n; i++) {
        del += deliveries[i];
        pic += pickups[i];

        while (del > 0 || pic > 0) {
            del -= cap;
            pic -= cap;
            answer += (n - i) * 2;
        }
    }


    return answer;
}