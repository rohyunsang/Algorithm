#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<int> dp;
    vector<int> dp_idx;
    vector<int> parent(n, -1);

    for (int i = 0; i < n; i++)
    {
        int x = A[i];
        auto it = lower_bound(dp.begin(), dp.end(), x);
        int pos = it - dp.begin();

        if (it == dp.end())
        {
            dp.push_back(x);
            dp_idx.push_back(i);
        }
        else
        {
            dp[pos] = x;
            dp_idx[pos] = i;
        }

        if (pos > 0)
        {
            parent[i] = dp_idx[pos - 1];
        }
    }

    cout << dp.size() << "\n";

    vector<int> lis;
    int idx = dp_idx.back();
    while (idx != -1)
    {
        lis.push_back(A[idx]);
        idx = parent[idx];
    }

    reverse(lis.begin(), lis.end());

    for (int x : lis)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
