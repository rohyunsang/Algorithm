#include <iostream>
#include <vector>

using namespace std;

int main() {

	vector<int> arr = { 8,1,4,9,1,3 };
	// �տ��� ¦�� �������� �ڿ��� Ȧ�� ��������. 
	int st = 0;
	int en = (int)arr.size() - 1;

	int ans = 0;

	while (st < en)
	{
		if (arr[st] % 2 == 0) st++;
		else if (arr[en] % 2 == 1) en--;
		else
		{
			// swap(arr[st], arr[en]) ���ص� �� 
			st++;
			en--;
			ans++;
		}
	}

	cout << ans;


	return 0; 
}