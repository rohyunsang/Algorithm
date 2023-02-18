#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    int cards1cnt = 0;
    int cards2cnt = 0;
    int cards1Size = cards1.size();
    int cards2Size = cards2.size();

    for(int i = 0 ; i < goal.size() ;i++){
        if(goal[i] == cards1[cards1cnt % cards1Size])
        {
            cards1cnt++;
        }
        else if(goal[i] == cards2[cards2cnt % cards2Size]){
            cards2cnt++;
        }
        else
        {
            answer = "No";
        }
    }

    return answer;
}
