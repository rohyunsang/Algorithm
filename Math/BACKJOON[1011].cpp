#include <iostream>

using namespace std;


// move k => next move k-1 or k or k + 1 
// but speed at which the goal 1 

/*

1 : 1                      #1 
2 : 1 1                    2  
3 : 1 2 1                  #4 
4 : 1 2 2 1                6  
5 : 1 2 3 2 1              #9 
6 : 1 2 3 3 2 1            12 
7 : 1 2 3 4 3 2 1          #16
8 : 1 2 3 4 4 3 2 1        20 


*/

int t;

int main() {
	cin >> t;

	while(t--){
		double x, y, result;
		cin >> x >> y;

		double i = 1;
		for (;; i++) {
			if (y - x < i * i)
				break;
		}

		if (y - x == (i - 1) * (i - 1)) {
			result = 2 * (i - 1) - 1;
		}
		else if (y - x < ((i - 1) * (i - 1) + i * i) / 2) {
			result = 2 * (i - 1);
		}
		else {
			result = 2 * i - 1;
		}
		cout << result << '\n';
	}
}
