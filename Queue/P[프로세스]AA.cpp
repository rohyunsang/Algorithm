#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;
queue<pair<int, int>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({ priorities[i],i });
    }

    while (!q.empty()) {
        int curFront = q.front().first;
        int idx = q.front().second;
        q.pop();

        if (curFront == pq.top()) {
            answer++;
            if (location == idx) {
                return answer;
            }
            pq.pop();
        }
        else {
            q.push({ curFront,idx });
        }


    }


    return answer;
}