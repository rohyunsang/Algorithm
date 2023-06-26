#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q; // 큐에는 (중요도, 위치) 쌍을 저장

    for (int i = 0; i < priorities.size(); ++i) {
        q.push({ priorities[i], i });
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        // q에서 데이터를 꺼냄 
        int currentPriority = q.front().first;
        int currentLocation = q.front().second;

        if (currentPriority < pq.top()) {  //우선 순위가 작으면 뒤로 이동 
            q.push(q.front());
            if(!q.empty()) q.pop();
        }
        else {  // 우선 순위가 같거나 크면 answer++; 
            answer++;
            if (currentLocation == location) {
                break;
            }
            if (!q.empty()) q.pop();
            if (!pq.empty()) pq.pop();
        }

    }

    return answer;
}