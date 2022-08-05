#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
    Console: "...!@BaT#*..y.abcdefghijklm" = > "bat.y.abcdefghi"

    1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
         만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
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