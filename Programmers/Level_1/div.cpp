#include <string>
#include <vector>

using namespace std;

int div(int n){
    int div_num = 0;
    for(int i = 1 ; i <= n; i++)
    {
        if(n % i == 0)
            div_num++;
    }
    return div_num;
}

int solution(int left, int right) {
    int answer = 0;
    for(int i = left ; i <= right ; i++){
        if(div(i) % 2 == 0)
        {
            answer += i;
        }
        else{
            answer -= i;
        }
    }
