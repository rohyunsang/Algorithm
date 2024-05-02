#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<pair<int, int>> q;
priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        q.push({ priorities[i], i });
    }

    while (!q.empty()) {

        int currentPriority = q.front().first;
        int currentIndex = q.front().second;
        q.pop();

        if (pq.top() == currentPriority) {
            pq.pop();
            answer++;
            if (currentIndex == location) {
                return answer;  
            }
        }
        else {  
            q.push({ currentPriority, currentIndex });
        }
    }
    return answer;
}
/*
int main() {
    vector<int> test = { 2, 1, 3, 2 };

    
    solution(test, 1)

    return 0;
}
*/
