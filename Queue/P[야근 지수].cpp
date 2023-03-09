#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> q;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int nTmp;
    for (const auto w : works)
        q.push(w);

    while (!q.empty() && n--) {
        nTmp = q.top();
        nTmp--;
        q.pop();
        if (nTmp)
            q.push(nTmp);
    }
    while (!q.empty()) {
        answer += q.top() * q.top();
        q.pop();
    }


    return answer;
}