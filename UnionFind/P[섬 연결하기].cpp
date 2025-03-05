#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> graph;

#define MAX 101

int parent[MAX];

int Find(int x) {
    if (parent[x] == x) return x;
    else
    {
        parent[x] = Find(parent[x]);
        return parent[x];
    }
}

void Merge(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    parent[y] = x;
}

bool SameParent(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;


    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (auto c : costs) {
        graph.push_back({ c[2],{c[1],c[0]} });
    }

    sort(graph.begin(), graph.end());

    for (auto g : graph) {
        int cost = g.first;
        int x = g.second.first;
        int y = g.second.second;

        if (SameParent(x, y) == false) {
            answer += cost;
            Merge(x, y);
        }
    }

    return answer;
}