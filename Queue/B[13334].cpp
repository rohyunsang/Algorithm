#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> arr[100000];

bool Compare(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.second == b.second)
        return a.first < b.first;

    return a.second < b.second;
}

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    int people_num, rail_len;
    cin >> people_num;

    int fr, se;
    for (int i = 0; i < people_num; ++i)
    {
        cin >> fr >> se;
        if (fr > se)
            swap(fr, se);
        arr[i].first = fr;
        arr[i].second = se;
    }

    sort(arr, arr + people_num, Compare);

    cin >> rail_len;

    int start, end;
    int include_cnt = 0, max_result = 0;

    for (int i = 0; i < people_num; ++i)
    {
        end = arr[i].second;
        start = end - rail_len;

        while (!pq.empty() && pq.top() < start)
        {
            --include_cnt;
            pq.pop();
        }

        if (arr[i].first >= start)
        {
            ++include_cnt;
            pq.push(arr[i].first);

            max_result = max(max_result, include_cnt);
        }

    }

    cout << max_result;

    return 0;
}