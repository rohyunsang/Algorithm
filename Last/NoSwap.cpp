#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> arr = { 8,1,4,9,1,3 };
	// 앞에는 짝수 팀원들이 뒤에는 홀수 팀원들이. 
	int st = 0;
	int en = (int)arr.size() - 1;

	int ans = 0;

	while (st < en)
	{
		if (arr[st] % 2 == 0) st++;
		else if (arr[en] % 2 == 1) en--;
		else
		{
			// swap(arr[st], arr[en]) 안해도 됨 
			st++;
			en--;
			ans++;
		}
	}

	cout << ans;


	return 0; 
}