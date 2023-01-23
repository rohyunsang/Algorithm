
#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string str)
{
    bool answer = true;
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {

        if (str[i] == '(') {
            s.push('(');
        }
        else if (!s.empty() && s.top() == '(' && str[i] == ')')
            s.pop();
        else
            s.push(str[i]);

    }
    if (s.empty())
        answer = true;
    else
        answer = false;


    return answer;
}