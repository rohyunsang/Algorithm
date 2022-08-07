#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    for(auto arr : arr)
        answer.push_back(arr);


    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}
