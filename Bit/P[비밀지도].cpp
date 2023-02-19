#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; i++)
    {
        string tmp = "";
        arr1[i] = arr1[i] | arr2[i];

        while (tmp.size() != n)
        {
            if (arr1[i] % 2 == 0)
                tmp = ' ' + tmp;
            else
                tmp = '#' + tmp;
            arr1[i] /= 2;
        }

        answer.push_back(tmp);
    }
    return answer;
}