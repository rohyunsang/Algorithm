#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string pattern;
    cin >> pattern;

    // 1) pattern을 regex 문자열로 변환
    //    '*' → "[a-z]*"
    //    그 외 문자(소문자) → 그대로 추가
    //    전체 매치 보장을 위해 ^ 와 $ 로 감싸줍니다.
    string re_str;
    re_str.push_back('^');
    for (char c : pattern)
    {
        if (c == '*')
        {
            re_str += "[a-z]*";
        }
        else
        {
            // c는 소문자이므로, 메타문자 이스케이프 불필요
            re_str.push_back(c);
        }
    }
    re_str.push_back('$');

    // 2) regex 객체 생성 (최적화 플래그 포함)
    regex re(re_str, regex::ECMAScript | regex::optimize);

    // 3) 각 파일명에 대해 전체 매치 검사
    while (N--)
    {
        string filename;
        cin >> filename;
        bool ok = regex_match(filename, re);
        cout << (ok ? "DA\n" : "NE\n");
    }

    return 0;
}