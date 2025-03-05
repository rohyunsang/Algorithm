#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <queue>
#include <map>

using namespace std;

vector<int> solution(vector<string> oper) {
    vector<int> answer;

    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> reverse_pq;
    map<int, int> m;

    for (int i = 0; i < oper.size(); i++) {
        // parsing 
        stringstream ss(oper[i]);
        string first;
        string second;
        ss >> first >> second;
        int num;
        num = stoi(second);

        if (first == "I") {
            pq.push(num);
            reverse_pq.push(num);
            m[num]++;
        }
        else if (first == "D") {
            if (num == 1) {
                while (!pq.empty() && m[pq.top()] == 0) {
                    pq.pop();
                }
                if (!pq.empty()) {
                    int max_num = pq.top();
                    pq.pop();
                    m[max_num]--;
                }
            }
            else {
                while (!reverse_pq.empty() && m[reverse_pq.top()] == 0) {
                    reverse_pq.pop();
                }
                if (!reverse_pq.empty()) {
                    int min_num = reverse_pq.top();
                    reverse_pq.pop();
                    m[min_num]--;
                }
            }
        }
    }

    while (!pq.empty() && m[pq.top()] == 0) pq.pop();
    while (!reverse_pq.empty() && m[reverse_pq.top()] == 0) reverse_pq.pop();

    if (pq.empty() || reverse_pq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(pq.top());
        answer.push_back(reverse_pq.top());
    }


    return answer;
}

// 이중 우선 순위 큐는 multiset 을 이용해서 꼭 풀자. 

