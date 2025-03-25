#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// �־��� �ߺ� ���� �������� �ڸ� �� �ִ��� Ȯ���ϴ� �Լ�
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

        // �ߺ� ������ ������ �Ѿ����� ���������� �ϳ��� �������� ����
        if (charCount[c] > maxDuplicates)
        {
            substrings.push_back(currentSubstring.substr(0, currentSubstring.size() - 1));
            cuts++;

            if (cuts > n) return false; // �ڸ��� Ƚ���� �ʰ��ϸ� false

            // �� ���� ����
            charCount.clear();
            charCount[c] = 1;
            currentSubstring = c;
        }

        i++;
    }

    substrings.push_back(currentSubstring); // ������ ���� �߰�
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

    // �̺� Ž������ ������ ������ �ִ� �ߺ� ������ ã��
    while (start <= end)
    {
        int mid = (start + end) / 2;
        vector<string> substrings;

        if (canCutWithMaxDuplicates(s, mid, n, substrings))
        {
            result = mid;
            finalSubstrings = substrings;  // ���� �߸� ���ڿ��� ����
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << "�ּ�ȭ�� �ߺ� ���ĺ� ����: " << result << endl;
    cout << "�߸� ���ڿ���:" << endl;
    for (const string& str : finalSubstrings)
    {
        cout << str << endl;
    }

    return 0;
}