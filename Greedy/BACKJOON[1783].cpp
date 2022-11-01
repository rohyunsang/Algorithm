#include <iostream>

using namespace std;
int n, m;

// 위 위 오 
// 위 오 오 
// 아 오 오
// 아 아 오 

int main(void)
{
    cin >> n >> m;
    if (n == 1)  
        cout << 1 << endl;
    else if (n == 2)  
        cout << min(4, (m + 1) / 2) << endl;

    else if (n >= 3)
    {
        if (m <= 6)
            cout << min(4, m) << endl;
        else  
            cout << m - 2 << endl;
    }

    return 0;

}