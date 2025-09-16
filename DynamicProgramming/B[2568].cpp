#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++)
        cin >> lines[i].first >> lines[i].second;

    sort(lines.begin(), lines.end());

    vector<int> b_positions;
    b_positions.reserve(n);
    for (int i = 0; i < n; i++)
        b_positions.push_back(lines[i].second);

    vector<int> lis;          
    vector<int> lis_idx;      
    vector<int> prev(n, -1);  // 핵심 경로 복원 

    for (int i = 0; i < n; i++)
    {
        int b = b_positions[i];
        int pos = int(lower_bound(lis.begin(), lis.end(), b) - lis.begin());
        if (pos == (int)lis.size())
        {
            lis.push_back(b);
            lis_idx.push_back(i);
        }
        else
        {
            lis[pos] = b;
            lis_idx[pos] = i;
        }
        if (pos > 0) prev[i] = lis_idx[pos - 1];
    }

    vector<char> inLis(n, false);
    int cur = lis_idx.empty() ? -1 : lis_idx.back();
    while (cur != -1)
    {
        inLis[cur] = true;
        cur = prev[cur];
    }

    vector<int> removed;
    removed.reserve(n - (int)lis.size());
    for (int i = 0; i < n; i++)
        if (!inLis[i]) removed.push_back(lines[i].first);

    cout << (int)removed.size() << '\n';
    for (int a : removed) cout << a << '\n';

    return 0;
}
