#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// dp

int dp[1001][1001] = { 0, };

int main() {

	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

    
    // Printing column headers
    cout << "  "; // Space for the row label
    for (char c : s2) {
        cout << c << " ";
    }
    cout << endl;

    // Printing the DP table with row headers
    for (int i = 1; i <= s1.size(); i++) {
        if (i == 0) {
            cout << "  "; // Extra space for the top-left corner when there is no row label
        }
        else {
            cout << s1[i - 1] << " "; // Print row label
        }

        for (int j = 1; j <= s2.size(); j++) {
            cout << dp[i][j] << " "; // Print DP values
        }
        cout << endl;
    }
    
    
    cout << dp[s1.size()][s2.size()];
	return 0; 
}

//   C A P C A K
// A 0 1 1 1 1 1
// C 1 1 1 2 2 2
// A 1 2 2 2 3 3
// Y 1 2 2 2 3 3
// K 1 2 2 2 3 4
// P 1 2 3 3 3 4
// 4


// https://www.acmicpc.net/problem/9251