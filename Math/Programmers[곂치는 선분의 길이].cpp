#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    map<float, int> m;

    for (int t = 0; t < 3; t++) {
        for (int i = lines[t][0]; i < lines[t][1]; i++) {
            m[i + 0.5]++;
        }
    }
    for (const auto m : m) {
        if (m.second >= 2)
            answer++;
    }

    return answer;
}