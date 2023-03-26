#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int> q;
int roundCnt = 1;


int solution(int n, int k, vector<int> enemy) {
    
    for (int i = 0; i < enemy.size(); i++) {
        if (n >= enemy[i]) {
            q.push(enemy[i]);
            n -= enemy[i];
        }
        else {
            if (k) {
                k--;
                if (!q.empty()) {
                    int temp = q.top();
                    q.pop();
                    if (temp >= enemy[i]) {
                        n += temp - enemy[i];
                        q.push(enemy[i]);
                    }
                    else q.push(temp);
                }
            }
            else return i;
        }
    }
    return enemy.size();
}