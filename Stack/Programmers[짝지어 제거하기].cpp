#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string str)
{
    int answer = 0;
    stack<char> s;
    for (int i = 0; i < str.size(); i++) {
        if (!s.empty() && s.top() == str[i])
            s.pop();
        else
            s.push(str[i]);

    }

    if (!s.empty())
        answer = 0;
    else
        answer = 1;


    return answer;
}