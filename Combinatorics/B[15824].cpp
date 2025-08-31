#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    ll n;
    ll arr[300005];
    ll two[300005];
    ll MOD = 1000000007;
    ll temp = 1;
    ll p = 0, m = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // two[i] = 2^i - 1

    for (int i = 0; i < n; i++)
    {
        two[i] = temp - 1;
        temp *= 2;
        temp %= MOD;
    }

    sort(arr, arr + n);

    // arr[i] 가 부분집합의 최댓값으로 등장하는 경우의 수는 2^i -1 
    // arr[i] 가 부분집합의 최솟값으로 등장하는 경우의 수는 2^(n-1-i) - 1

    for (int i = n - 1; i > 0; i--)
    {
        p += two[i] * arr[i];
        m += two[i] * arr[n - 1 - i];
        p %= MOD;
        m %= MOD;
    }
    cout << (p % MOD + MOD - m % MOD) % MOD << '\n';
}