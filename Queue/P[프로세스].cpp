#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int, int>> q; // ť���� (�߿䵵, ��ġ) ���� ����

    for (int i = 0; i < priorities.size(); ++i) {
        q.push({ priorities[i], i });
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        // q���� �����͸� ���� 
        int currentPriority = q.front().first;
        int currentLocation = q.front().second;

        if (currentPriority < pq.top()) {  //�켱 ������ ������ �ڷ� �̵� 
            q.push(q.front());
            if(!q.empty()) q.pop();
        }
        else {  // �켱 ������ ���ų� ũ�� answer++; 
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