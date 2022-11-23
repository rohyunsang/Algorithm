#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    int nMin = *min_element(arr.begin(), arr.end());
    *min_element is good
*/


vector<int> solution(vector<int> arr) {
    vector<int> answer;



    answer = arr;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < answer.size(); i++) {
        if (arr[0] == answer[i])
        {
            answer.erase(answer.begin() + i);
        }
    }

    if (answer.size() == 0)
    {
        answer.push_back(-1);
    }



    return answer;
}