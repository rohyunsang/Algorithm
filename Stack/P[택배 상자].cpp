#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    int idx = 1;

    while (idx < order.size() + 1) {
        s.push(idx);
        while (!s.empty() && s.top() == order[answer]) {
            //cout << "idx : " << idx << " s.top : " << s.top() << " order[answer] : " << order[answer] << endl;
            answer++;
            s.pop();


            if (s.size() == 0)
                break;
        }
        idx++;
    }


    return answer;
}