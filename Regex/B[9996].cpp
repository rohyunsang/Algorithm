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

    // 1) pattern�� regex ���ڿ��� ��ȯ
    //    '*' �� "[a-z]*"
    //    �� �� ����(�ҹ���) �� �״�� �߰�
    //    ��ü ��ġ ������ ���� ^ �� $ �� �����ݴϴ�.
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
            // c�� �ҹ����̹Ƿ�, ��Ÿ���� �̽������� ���ʿ�
            re_str.push_back(c);
        }
    }
    re_str.push_back('$');

    // 2) regex ��ü ���� (����ȭ �÷��� ����)
    regex re(re_str, regex::ECMAScript | regex::optimize);

    // 3) �� ���ϸ� ���� ��ü ��ġ �˻�
    while (N--)
    {
        string filename;
        cin >> filename;
        bool ok = regex_match(filename, re);
        cout << (ok ? "DA\n" : "NE\n");
    }

    return 0;
}