#include<iostream>

using namespace std;

// a, b의 최소공배수는 a * b / gcd(a, b) (gcd = 최대공약수)

int Divide(int x, int y)
{
    if (x % y == 0)
        return y;
    else
        return Divide(y, x % y);
}

int main()
{
    int T;
    int A, B;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        if (A >= B)
        {
            cout << A * B / Divide(A, B) << "\n";
        }
        else
            cout << A * B / Divide(B, A) << "\n";
    }
}
