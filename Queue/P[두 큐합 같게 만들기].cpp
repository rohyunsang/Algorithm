#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    queue<int> q1;
    queue<int> q2;

    long long q1Sum = 0;
    long long q2Sum = 0;
    long long qSum = 0;

    for (int i = 0; i < queue1.size(); i++) {
        q1.push(queue1[i]);
        q1Sum += queue1[i];
    }
    for (int i = 0; i < queue2.size(); i++) {
        q2.push(queue2[i]);
        q2Sum += queue2[i];
    }
    qSum = q1Sum + q2Sum;
    if (qSum / 2 == 1) return -1;

    int n = queue1.size();

    for (int i = 0; i < 3 * n; i++) {
        if (q1Sum > q2Sum) {
            int x = q1.front();
            q1Sum -= x;
            q2Sum += x;
            q1.pop();
            q2.push(x);
        }
        else if (q1Sum < q2Sum) {
            int x = q2.front();
            q1Sum += x;
            q2Sum -= x;
            q2.pop();
            q1.push(x);
        }
        else {
            return answer;
        }
        answer++;
    }

    return -1;
}