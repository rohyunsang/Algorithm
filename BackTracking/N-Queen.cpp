#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;
int N;
vector<int> v;

bool Check(int row) {
    for (int i = 0; i < row; i++) {
        if (v[i] == v[row] || abs(v[row] - v[i]) == row - i)
            return false;
    }
    return true;
}

void BackTracking(int x) {
    if (x == N)
        cnt++;
    else
        for (int i = 0; i < N; i++) {
            v[x] = i;
            if (Check(x))
                BackTracking(x + 1);
        }
}

int solution(int n) {
    int answer = 0;
    N = n;

    for (int i = 0; i < n; i++) {
        v.push_back(0);
    }

    BackTracking(0);

    answer = cnt;

    return answer;
}