#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>


using namespace std;

bool div(int n) //Divisor
{
    if(n<2)
        return false;
    for(int i = 2 ; i * i <= n ; i++)
    {
        if (n % i ==0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(),numbers.end());
    map<int,int> m;

    //BitMask for (int subset = A ; subset ; subset = ((subset - 1) & A))

    for(int i = 1; i < (1 << numbers.size());i++)
    {
        vector<char> v;
        for(int j = 0 ; j < numbers.size() ; j++)
        {
            if(i & (1 << j)){
                v.push_back(numbers[j]);
            }
        }

        do{
            string s = "";
            for(int k = 0 ; k < v.size() ; k++)
            {
                s += v[k];
            }

            if(div(stoi(s)))
                m[stoi(s)]++;
        }while(next_permutation(v.begin(),v.end()));
    }
    answer = m.size(); 



    return answer;
}
