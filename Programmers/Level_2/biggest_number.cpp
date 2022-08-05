#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//custom compare
bool compare(const string &a,const string &b)
{
    return a + b > b + a;
}


string solution(vector<int> numbers) {
    vector<string> strnums;
    string answer = "";

    for (int i = 0 ; i < numbers.size(); i++){
        strnums.push_back(to_string(numbers[i]));
    }
    sort(strnums.begin(), strnums.end(), compare);

    for(int i = 0 ; i < strnums.size(); i++){
        answer += strnums[i];
    }
    if(answer[0] == '0') return "0";

    return answer;
}
