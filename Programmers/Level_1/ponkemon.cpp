#include <vector>
#include <algorithm>


using namespace std;

// if n => get N/2
// nC2 Combination

// 3 1 2 3 => 1 2 3 
// 3 3 3 2 2  4 => 2 3 4
// 3 3 3 2 2 2 => 2 3 

int solution(vector<int> nums)
{

    int n = (int)nums.size() / 2;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    int answer = 0;
    if (nums.size() <= n)
    {
        answer = nums.size();
    }
    else {
        answer = n;
    }


    return answer;
}