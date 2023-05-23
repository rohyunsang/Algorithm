#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Implement fast swap algorithm 
// pick data structure 

map<int, string> originMap;
map<string, int> chasingMap;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;

    for (int i = 0; i < players.size(); i++) {
        originMap[i] = players[i];
        chasingMap[players[i]] = i;
    }
    
    for (int i = 0; i < callings.size(); i++) {
        int curIdx = chasingMap[callings[i]];
        string sTmp = originMap[curIdx - 1];
        originMap[curIdx - 1] = callings[i];
        originMap[curIdx] = sTmp;
        chasingMap[callings[i]] = curIdx - 1;
        chasingMap[sTmp] = curIdx;
    }

    

    for (const auto origin : originMap)
        answer.push_back(origin.second);

    return answer;
}