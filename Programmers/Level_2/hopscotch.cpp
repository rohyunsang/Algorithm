#include <iostream>
#include <vector>
#include <algorithm>
//Dynamic
using namespace std;

int solution(vector<vector<int> > v)
{
    int answer = 0;
    
    for(int i = 0 ; i < v.size()-1; i++)
    {
        //for(int j = 0 ; j < 4 ; j++)
        //    v[i+1][j] += max(v[i][1],max(v[i][2],v[i][3]));
        
        v[i+1][0] += max(v[i][1],max(v[i][2],v[i][3]));
        v[i+1][1] += max(v[i][0],max(v[i][2],v[i][3]));
        v[i+1][2] += max(v[i][0],max(v[i][1],v[i][3]));
        v[i+1][3] += max(v[i][0],max(v[i][1],v[i][2]));

    }
    sort(v[v.size()-1].begin(),v[v.size()-1].end());
    answer = v[v.size()-1][3];

    return answer;
}
