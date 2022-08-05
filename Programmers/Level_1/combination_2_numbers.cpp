#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {

    // i  = 0  j = 1 2 3 4 
    // i  = 1  j = 2 3 4
    // i  = 2  j = 3 4
    // i  = 3  j = 4

    vector<int> answer;

    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            auto sum = numbers[i] + numbers[j];
            answer.push_back(sum);
        }
    }
    
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());


    for (auto ans : answer) {
        cout << ans;
    }

    return answer;
}

int main() {

    vector<int> numbers;

    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(1);

    solution(numbers);
    
    return 0;
}
