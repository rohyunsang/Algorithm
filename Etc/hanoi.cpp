#include <iostream>

using namespace std;
int n;

void hanoi(int n, int from, int by, int to) {
    cout << "start hanoi recursion" << endl;
    if (n == 1) {
        cout << from << " " << to << endl;
    }
    else {
        hanoi(n - 1, from, to, by);
        cout << "form " << from << " to " << to << endl;
        hanoi(n - 1, by, from, to);
        cout << "form " << from << " to " << to << endl;
    }
}


int main() {
    cin >> n;
    hanoi(n, 1, 2, 3);
}


/*
3 2 1         

3 2            1

3       2      1

3       2 1    

        2 1    3

1       2      3

1              3 2

               3 2 1
*/

/*
        A          B           C           
        4321
        432         1
        43          1       2
        43                   21
        4           3       21
        41          3       2
        41          32  
        4           321 
                    321        4

                    `
                    `
                    `
                    `
                    `
                             4321

*/

// 2^n - 1