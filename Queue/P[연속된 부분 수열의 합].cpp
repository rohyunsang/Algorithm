#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//two pointer
queue<pair<int, int>> q;

vector<int> solution(vector<int> s, int k) {
    vector<int> answer;
    answer.push_back(-1);
    answer.push_back(-1);
    int n = (int)s.size();
    int sum = 0;
    int len = 1987654321;

    for (int i = 0; i < n; i++) {
        q.push({ s[i],i });
        sum += s[i];
        while (sum > k) {
            sum -= q.front().first;
            q.pop();
        }
        if (sum == k && q.size() < len)
        {
            len = q.size();
            answer[0] = q.front().second;
            answer[1] = q.back().second;
        }
    }


    return answer;
}
