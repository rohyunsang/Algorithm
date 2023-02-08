#include <string>
#include <vector>

using namespace std;

// 11  42
// 12  44
// 13  111
// 14  112
// 15  114
// 16  121
// 17  122
// 18  124
// 19  141  3^2  3^1 * 3  3^0

// 3^n 


string solution(int n) {
    string answer = "";
    int remainder;

    while (n > 0) {
        remainder = n % 3;
        n = n / 3;
        if (remainder == 0) {
            answer = "4" + answer;
            n--;
        }
        else if (remainder == 1)
            answer = "1" + answer;
        else
            answer = "2" + answer;

    }
    // answer += "1";
    // answer = "1" + answer; 
    // changing string 


    return answer;
}