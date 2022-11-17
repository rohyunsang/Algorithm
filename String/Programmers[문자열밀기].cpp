#include <string>

using namespace std;

int solution(string A, string B)
{
    B += B;
    return B.find(A);
}