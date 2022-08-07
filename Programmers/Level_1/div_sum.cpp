#include <string>
#include <vector>

using namespace std;

int divSum(int n){
    int sum = 0;
    for(int i = 1 ; i <= n ; i++)
        if(n%i == 0)
            sum += i;
    return sum;
}

int solution(int n) {
    int answer = divSum(n);
    return answer;
}
