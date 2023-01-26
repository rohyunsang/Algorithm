#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for (const auto& c : clothes) {
        m[c[1]] += 1;
    }
    for (auto it = m.begin(); it != m.end(); it++) {
        answer *= it->second + 1;
    }
    // map for => 
    /*
    for(auto it = m.begin(); it != m.end(); it++){
        it->second or it->first
    }

    */

    answer += -1;
    return answer;
}