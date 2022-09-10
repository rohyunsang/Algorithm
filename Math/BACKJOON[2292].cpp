#include <iostream>

using namespace std;
int n;
int cnt = 6;
int result = 1;
int number = 1;

int main(){
    cin >>n;
    
    while(1){
        if(number >= n){
            cout << result << endl;
            return 0;
        }
        number += cnt;
        cnt += 6;
        result++;
    }
    
    
    return 0;
}
