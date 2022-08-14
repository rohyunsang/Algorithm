#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    int cnt = 0;
    
    long long tmep = num;
    
    while(cnt <=500)
    {
        if(tmep == 1)
            break;
        
        if(tmep % 2 == 0)
        {
            tmep = tmep / 2;
        }
        else
        {
            tmep = (tmep * 3) + 1;
        }
        cnt++;
    }
    
    if(cnt >= 500)
        return -1;
    else
        return cnt;
    
    
}
