#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// k    	dungeons                 	result
// 80   [[80, 20], [50, 40], [30, 10]]       3

int dunSize;
int needs[8];
int uses[8];
bool check[8] = { false, };
int result = 0;

void dfs(int cnt, int remain) {
    for (int i = 0; i < dunSize; i++) {
        if (!check[i] && needs[i] <= remain) {
            check[i] = true;
            dfs(cnt + 1, remain - uses[i]);
            check[i] = false;
        }
    }
    result = max(result, cnt);
    return;

}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    dunSize = dungeons.size();

    for (int i = 0; i < dunSize; i++) {
        needs[i] = dungeons[i][0];
        uses[i] = dungeons[i][1];
    }

    dfs(0,k);

    answer = result;

    return answer;
}