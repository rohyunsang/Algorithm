#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    sort(scoville.begin(), scoville.end());
    priority_queue<int, vector<int> , greater<int>> pq;
    
    for(auto sco : scoville) 
        pq.push(sco);
    
    while(pq.top() < K){
        if(pq.size() == 1) return -1;
        
        int tmp1 = pq.top();
        pq.pop();
        
        int tmp2 = pq.top();
        pq.pop();
        
        int new_sco = tmp1 + tmp2 * 2;
        pq.push(new_sco);
        
        answer++;
    }
    
    
    
    
    return answer;
}
