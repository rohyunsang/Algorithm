#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> ticket;
vector<string> answer;

bool check[10001];
bool isAnswer;

void dfs(string start, int ticketCnt) {
    answer.push_back(start);

    if (ticketCnt == ticket.size()) {
        isAnswer = true;
        return;
    }

    for (int i = 0; i < ticket.size(); i++) {
        if (check[i]) continue;
        if (ticket[i][0] == start) {
            check[i] = true;
            dfs(ticket[i][1], ticketCnt + 1);

            if (!isAnswer) {
                answer.pop_back();
                check[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    stable_sort(tickets.begin(), tickets.end());
    /*
    for(auto t : tickets){
        cout << t[0] << " "<< t[1] << endl;
    }
    */
    ticket = tickets;
    dfs("ICN", 0);

    return answer;
}