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

    int answer_array[7] = { 6,6,5,4,3,2,1 };
    //vector<int> answer_vector;
        
    vector<int> answer;
    answer.push_back(answer_array[zero_count + equal_count]);
    answer.push_back(answer_array[equal_count]);

    return answer;
}