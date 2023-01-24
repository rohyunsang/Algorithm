#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;

    int idx = 0;

    //1 same word
    for (int i = 0; i < words.size() - 1; i++) {
        for (int j = i + 1; j < words.size(); j++) {
            cout << i << " " << j << " " << endl;
            if (words[i] == words[j]) {
                idx = j;
                break;
            }
        }
    }
    cout << idx << endl;

    //2 wrong char
    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i][words[i].size() - 1] != words[i + 1][0]) {
            idx = idx == 0 ? max(idx, i + 1) : min(idx, i + 1);
            cout << "wrong break" << endl;
            break;
        }

    }
    cout << idx;

    if (idx == 0)
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back((idx % n) + 1);
        answer.push_back((idx / n) + 1);
    }
    // cnt 2 5 8 => 3 
    // cnt 0 1 2 => 1 // 3 4 5 => 2 
    return answer;
}