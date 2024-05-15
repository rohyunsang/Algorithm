#include <string>
#include <vector>

using namespace std;

void DFS(int from, int n, vector<int>& visited, vector<vector<int>>& computers) {

    for (int i = 0; i < n; i++) {
        if (from != i && computers[from][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            DFS(i, n, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    int network = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 1) {
            continue;
        }

        // visit node and start DFS
        network++;
        visited[i] = 1;

        DFS(i, n, visited, computers);
    }

    return network;
}
