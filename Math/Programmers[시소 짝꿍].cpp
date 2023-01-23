#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 2 3 4 



long long solution(vector<int> weights) {
    long long answer = 0;

    sort(weights.begin(), weights.end());

    for (int i = 0; i < weights.size() - 1; i++) {
        for (int j = i + 1; j < weights.size(); j++) {
            if (weights[i] == weights[j])
                answer++;
            else if (weights[i] * 2 == weights[j])
                answer++;
            else if ((weights[i] / 3) * 4 == weights[j] && weights[i] % 3 == 0)
                answer++;
            else if ((weights[i] / 2) * 3 == weights[j] && weights[i] % 2 == 0)
                answer++;
        }

    }

    return answer;
}
