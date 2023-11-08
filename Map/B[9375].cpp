#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;

    int n;
    string name, category;

    while (t--)
    {
        map<string, int> m;
        cin >> n;
        while (n--)
        {
            cin >> name >> category;
            m[category]++;
        }

        int ans = 1;
        for (auto m : m)
        {
            ans *= (m.second + 1);
        }
        ans -= 1;
        cout << ans << '\n';
    }

    return 0;
}