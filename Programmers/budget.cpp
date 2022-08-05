#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int solution(vector<int> d, int budget) {

    sort(d.begin(),d.end());
    int answer = 0;
    for(auto d : d)
    {
        budget -= d;
        if(budget>=0)
            answer++;
        else
            break;
    }


    return answer;
}
