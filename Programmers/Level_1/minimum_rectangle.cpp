#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> sizes) {

    for(int i = 0 ; i < sizes.size() ; i++)
    {
        if(sizes[i][0] < sizes[i][1])
        {
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    sort(sizes.begin(),sizes.end());

    int h = sizes[sizes.size()-1][0];

    for(int i = 0 ; i < sizes.size() ; i++)
    {
        if(sizes[i][0] > sizes[i][1])
        {
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    sort(sizes.begin(),sizes.end());
    int w = sizes[sizes.size()-1][0];

    int answer = 0;

    answer = h * w;

    return answer;
}

// *********************
// <algorithm> min , max 
int w=0, h=0;
    for(int i=0; i<sizes.size(); i++)
    {
        w=max(w,min(sizes[i][0],sizes[i][1]));
        h=max(h,max(sizes[i][0],sizes[i][1]));
    }

