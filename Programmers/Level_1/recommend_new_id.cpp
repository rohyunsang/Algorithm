#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
    Console: "...!@BaT#*..y.abcdefghijklm" = > "bat.y.abcdefghi"

    1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
    2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
    3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
    4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
    5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
    6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
         ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
    7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
*/



string solution(string new_id) {

    //1.
    for (int i = 0; i < new_id.size(); i++) {
        new_id[i] = tolower(new_id[i]);
    }

    //2.
    for (auto idx = 0; idx < new_id.size(); idx++) {
        auto& new_id_char = new_id.at(idx);
        if (!islower(new_id_char) && !isdigit(new_id_char) &&
            (new_id_char != '-') && (new_id_char != '_') && (new_id_char != '.')) 
        {
             new_id.erase(idx--, 1);
        }
    }

    //3.
    auto pos = 0;
    while ((pos = new_id.find("..")) != string::npos) {
        new_id.replace(pos, 2, ".");
    }
    
    //4.
    if (new_id.front() == '.') {   // begin , end || front , back 
        new_id.erase(new_id.begin());
    }
    if (new_id.back() == '.') {
        new_id.pop_back();
    }

    //5.
    if (new_id.empty()) {
        new_id = "a";
    }
    
    //6. 
    if (new_id.size() >= 16) {
        new_id = new_id.substr(0, 15); //0~15 return 
        if (new_id.back() == '.') {
            new_id.pop_back();
        }
    }

    //7.
    while (new_id.size() < 3) {
        new_id.push_back(new_id.back());
    }

    string answer = new_id;
    return answer;
}

int main() {
    cout << solution("@DdkSKWdksjdks");

    return 0;
}