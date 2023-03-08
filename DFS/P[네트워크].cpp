#include <string>
#include <vector>

using namespace std;

vector<int> v[201];
bool visited[201];
int cnt = 0;

void dfs(int start_, vector<vector<int>> computers) {
    visited[start_] = true;

    for (int i = 0; i < computers.size(); i++) {
        if (!visited[i] && computers[start_][i] == 1) {
            dfs(i, computers);
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, computers);
            cnt++;
        }
    }
    answer = cnt;
    return answer;
}