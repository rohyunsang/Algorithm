#include <iostream>
#include <vector>

using namespace std;

int parent[51];

int Find(int x) {
    if (x == parent[x]) return x;
    parent[x] = Find(parent[x]);
    return parent[x];
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a != b) parent[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    int trueCnt;
    cin >> trueCnt;

    for (int i = 0; i <= n; i++) parent[i] = i;

    vector<int> trueKnower;
    trueKnower.reserve(trueCnt);
    for (int i = 0; i < trueCnt; i++)
    {
        int trueManNum;
        cin >> trueManNum;
        trueKnower.push_back(trueManNum);
    }


    vector<vector<int>> parties;
    parties.reserve(m);

    for (int i = 0; i < m; i++)
    {
        int cnt;
        cin >> cnt;
        vector<int> tmp;
        tmp.reserve(cnt);
        for (int j = 0; j < cnt; j++)
        {
            int nTmp;
            cin >> nTmp;
            tmp.push_back(nTmp);
        }

        for (int j = 0; j < cnt - 1; j++)
        {
            Union(tmp[j], tmp[j + 1]);
        }

        parties.push_back(move(tmp));
    }


    bool truthRoot[51] = { false };
    for (int t : trueKnower)
    {
        truthRoot[Find(t)] = true;
    }

    int ans = 0;
    for (const auto& p : parties)
    {
        bool canExaggerate = true;
        for (int person : p)
        {
            if (truthRoot[Find(person)])
            {
                canExaggerate = false;
                break;
            }
        }
        if (canExaggerate) ans++;
    }

    cout << ans << '\n';
    return 0;
}
