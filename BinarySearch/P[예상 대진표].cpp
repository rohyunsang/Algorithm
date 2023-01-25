#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    int nTmp;
    if (a > b) {
        nTmp = a;
        a = b;
        b = nTmp;
    }
    cout << a << " " << b << " " << nTmp;

    while (true) {
        answer++;
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        if (a == b)
            break;
    }

    return answer;
}
