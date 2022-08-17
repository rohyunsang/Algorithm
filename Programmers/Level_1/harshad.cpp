#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int tmp = x;
    
    while(tmp > 0)
    {
        sum = sum + (tmp % 10);
        tmp = tmp / 10;
    }
    
    if(x % sum == 0)
        return true;
    else
        return false;
    
    
}
