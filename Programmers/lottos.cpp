#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// Console : solution([44,1,0,0,31,25],[31,10,45,1,6,19]) => result[3,5];
vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    auto zero_count = count(lottos.begin(), lottos.end(), 0);
    auto equal_count = 0;

    for (const auto lotto : lottos) {
        if (find(win_nums.begin(), win_nums.end(), lotto) != win_nums.end()) {
            equal_count++;
        }
    }

    vector<int> answer_vector;

    answer_vector.push_back(6);
    answer_vector.push_back(6);
    answer_vector.push_back(5);
    answer_vector.push_back(4);
    answer_vector.push_back(3);
    answer_vector.push_back(2);
    answer_vector.push_back(1);

    vector<int> answer;
    answer.push_back(answer_vector[zero_count + equal_count]);
    answer.push_back(answer_vector[equal_count]);

    return answer;
}