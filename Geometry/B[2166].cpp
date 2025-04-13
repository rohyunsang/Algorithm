#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({ x, y });
    }

    v.push_back(v[0]); 

    long long area2 = 0;  // 넓이 * 2

    for (int i = 0; i < n; i++)
    {
        area2 += 1LL * v[i].first * v[i + 1].second;
        area2 -= 1LL * v[i].second * v[i + 1].first;
    }

    double area = fabs(area2) / 2.0;

    printf("%.1f\n", area);  // 소수점 첫째 자리까지

    return 0;
}
