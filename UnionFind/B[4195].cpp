#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> parent, netSize;

int Find(int x)
{
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

int Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (a != b)
    {
        parent[b] = a;
        netSize[a] += netSize[b];
    }
    return netSize[a];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--)
    {
        int F; cin >> F;

        parent.clear();
        netSize.clear();
        parent.resize(F * 2);  
        netSize.resize(F * 2, 1);

        unordered_map<string, int> id;
        int idx = 0;

        for (int i = 0; i < F; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;

            if (id.find(s1) == id.end())
            {
                id[s1] = idx;
                parent[idx] = idx;
                netSize[idx] = 1;
                idx++;
            }
            if (id.find(s2) == id.end())
            {
                id[s2] = idx;
                parent[idx] = idx;
                netSize[idx] = 1;
                idx++;
            }

            int result = Union(id[s1], id[s2]);
            cout << result << "\n";
        }
    }
}

// memory -> string to int 