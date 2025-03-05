#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    vector<int> v;
    int n, input;
    int start, end;
    int ans = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    if (n <= 2) {
        cout << 0;
        return 0;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        vector<int> copy_v = v;
        copy_v.erase(copy_v.begin() + i);

        start = 0; end = n - 2;

        while (start < end) {
            int sum = copy_v[start] + copy_v[end];

            if (sum == v[i]) {
                ans++;
                break;
            }

            if (sum < v[i]) start++;
            else end--;
        }
    }

    cout << ans;

    return 0;
}