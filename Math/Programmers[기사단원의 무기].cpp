#include <string>
#include <vector>
#include <cmath>
using namespace std;

int divCount =0;

int div(int n){
    divCount = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divCount++;
        if (i * i < n) {
            divCount++;
        }
    }
}
    return divCount;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> v(100001);
    for(int i =1 ; i<= number ; i++){
        v.push_back(i);
    }
    for(int i=0;i < v.size() ; i++){
        if(div(v[i]) > limit){
            answer += power;
        }
        else{
            answer += div(v[i]);
        }


    }

    return answer;
}
