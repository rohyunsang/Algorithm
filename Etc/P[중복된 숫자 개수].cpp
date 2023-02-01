#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;

    sort(array.begin(), array.end());
    const auto p = equal_range(array.begin(), array.end(), n);
    answer = p.second - p.first;

    return answer;
}