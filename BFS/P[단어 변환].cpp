#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    words.push_back(begin);

    sort(words.begin(), words.end());

    vector<vector<int>> graph(51);

    int n = words.size();
    int wordElementSize = (int)words[0].size();


    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int cnt = 0;

            for (int k = 0; k < wordElementSize; k++) {

                if (words[i][k] == words[j][k]) {
                    cnt++;
                }
            }
            if (cnt == wordElementSize - 1) {
                graph[i].push_back(j);
                graph[j].push_back(i);
                cout << i << " " << j << " i ¿Í j ¿¬°á " << endl;
            }
        }
    }

    int startIdx = 0;
    int targetIdx = 0;
    bool isFail = true;
    int d[51];

    for (int i = 0; i < n; i++) {
        d[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        if (words[i] == begin) {
            startIdx = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (words[i] == target) {
            targetIdx = i;
            isFail = false;
            break;
        }
        isFail = true;
    }

    cout << startIdx << " " << targetIdx << " start, target" << endl;

    if (isFail) return 0;
    bool visited[51] = { false };
    queue<pair<int, int>> q;
    q.push({ startIdx, 0 });
    visited[startIdx] = true;



    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur == targetIdx) {
            return cnt;
        }

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];

            if (visited[next] == false) {
                visited[next] = true;
                q.push({ next,cnt + 1 });
                cout << next << " " << " cnt " << cnt + 1 << endl;
            }
        }
    }



    return answer;
}
