#include <string>
#include <vector>
#include <algorithm>

bool compare(const int &a , const int &b)
{
    return a > b;
}

using namespace std;

string solution(string s) {

    sort(s.begin(),s.end(),compare);

    string answer = "";
    answer = s;
    return answer;
}
