#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;

    int sum = 0;

    for(auto arr : arr)
    {
        sum += arr;

    }

    answer = sum / (double) arr.size();
    return answer;
}

// /#include <numeric>
// double answer = accumulate(arr.begin(), arr.end(), 0);
