#include <string>
#include <vector>

using namespace std;


long long solution(int a, int b) {
    long long answer = 0;

    if(a > b)
        for(b ; b <=a ; b++)
            answer+=b;
    else if(a < b)
        for(a ; a <=b ; a ++)
            answer+=a;
    else
        answer = a;


    return answer;
}
