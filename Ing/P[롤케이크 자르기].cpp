#include <string>
#include <vector>
#include <algorithm>
#include <map> 

using namespace std;

vector<int> copy_topping;
map<int, int> left_topping;
map<int, int> total_topping;


int solution(vector<int> topping) {
    int answer = 0;

    for (int i = 0; i < topping.size(); i++) {
        total_topping[i]++;
    }

    for (int i = 1; i < topping.size(); i++) {
        for (int j = 0; j < i; j++) {
            left_topping[topping[j]]++;
            total_topping[topping[j]]--;
            if (total_topping[topping[j]] <= 0)
                total_topping.erase(topping[j]);
        }
        if (left_topping.size() == total_topping.size()) {
            answer++;
        }
        //left_topping.clear();
        //right_topping.clear();
    }

    return answer;
}