#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 주어진 중복 개수 기준으로 자를 수 있는지 확인하는 함수
bool canCutWithMaxDuplicates(const string& s, int maxDuplicates, int n, vector<string>& substrings) {
    int cuts = 0;
    substrings.clear();
    unordered_map<char, int> charCount;
    string currentSubstring;
    int i = 0;

    while (i < s.size())
    {
        char c = s[i];
        charCount[c]++;
        currentSubstring += c;

        // 중복 개수가 기준을 넘었으면 이전까지를 하나의 조각으로 간주
        if (charCount[c] > maxDuplicates)
        {
            substrings.push_back(currentSubstring.substr(0, currentSubstring.size() - 1));
            cuts++;

            if (cuts > n) return false; // 자르는 횟수가 초과하면 false

            // 새 조각 시작
            charCount.clear();
            charCount[c] = 1;
            currentSubstring = c;
        }

        i++;
    }

    substrings.push_back(currentSubstring); // 마지막 조각 추가
    return cuts <= n;
}

int main() {
    string s;
    int n;
    cin >> s >> n;

    int start = 1;
    int end = s.size();
    int result = s.size();
    vector<string> finalSubstrings;

    // 이분 탐색으로 가능한 최적의 최대 중복 개수를 찾음
    while (start <= end)
    {
        int mid = (start + end) / 2;
        vector<string> substrings;

        if (canCutWithMaxDuplicates(s, mid, n, substrings))
        {
            result = mid;
            finalSubstrings = substrings;  // 최종 잘린 문자열을 저장
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << "최소화된 중복 알파벳 개수: " << result << endl;
    cout << "잘린 문자열들:" << endl;
    for (const string& str : finalSubstrings)
    {
        cout << str << endl;
    }

    return 0;
}