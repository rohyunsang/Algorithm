#include <string>
#include <vector>


using namespace std;


int solution(int n) {
    vector<int> ternary;

    while(n){
        ternary.push_back(n % 3);
        n = n / 3;        
    }

    int answer = 0;
    int mul = 1;
    for(int i = ternary.size() -1 ; i>=0; i--){
        answer += ternary[i] * mul;
        mul *= 3;
    }

    return answer;
}
