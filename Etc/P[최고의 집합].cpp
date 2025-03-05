#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s) {
        answer.push_back(-1);
        return answer;
    }

    int target = s / n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(target);
    }

    int offset;
    offset = s - n * target;
    while (true) {
        for (int i = 0; i < n; i++) {
            if (offset > 0) {
                v[i]++;
                offset--;
            }
            else {
                break;
            }
        }
        if (offset <= 0) break;
    }
    /*
    for(auto v : v){
        cout << v << " " << endl;
    }
    */
    sort(v.begin(), v.end());
    answer = v;

    return answer;
}
