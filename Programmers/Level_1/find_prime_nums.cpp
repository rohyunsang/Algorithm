#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 2 < n <<1,000,000  O N^2

int solution(int n) {
    int answer = 0;

    for(int i = 2 ; i <= n ; i++)
    {
        for (int j = 2 ; j * j <= i ; j++) //
        {
            if(i % j == 0)
            {
                answer++;
                break;  
            }
        }
    }

    return (n-1) - answer;
}
