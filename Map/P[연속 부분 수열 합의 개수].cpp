#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

map<int, int> m;

int solution(vector<int> elements) {
    int answer = 0;

    // copy
    vector<int> v = elements;

    for (const auto e : elements)
        m[e]++;

    for (int i = 1; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
            v[j] += elements[(j + i) % v.size()];
            m[v[j]]++;
        }
    }

    //for(const auto m : m)
        //cout << m.first << " " ;
    answer = m.size();

    return answer;
}

// 0 1 2 3 4 5 6 7 8
// 01 12 23 34 
// 012 123 234
// 0123 1234 