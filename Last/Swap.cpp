#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 배열의 앞에는 짝수가. 배열의 뒤에는 홀수가. 
// 최소한의 배열의 이동 수. 

int main() {
	vector<int> arr = { 8,1,4,7 };
	// 8 1 4 7
	// 8 4 1 7 
	// ans is 1 

	int ans = 0;
	cin >> ans; 

	int st = 0;
	int en = (int)arr.size() - 1;

	while (st <= en) // st <= en 
	{
		if (arr[st] % 2 == 0)  // 시작이 짝수
		{
			st++;
		}
		else if (arr[en] % 2 == 1) // 끝이 홀수
		{
			en--;
		}
		else // 시작이 홀수, 끝이 짝수 
		{
			swap(arr[st], arr[en]);
			st++;
			en--;
			ans++;
		}
	}


	return 0; 
}