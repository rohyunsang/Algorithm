#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// �迭�� �տ��� ¦����. �迭�� �ڿ��� Ȧ����. 
// �ּ����� �迭�� �̵� ��. 

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
		if (arr[st] % 2 == 0)  // ������ ¦��
		{
			st++;
		}
		else if (arr[en] % 2 == 1) // ���� Ȧ��
		{
			en--;
		}
		else // ������ Ȧ��, ���� ¦�� 
		{
			swap(arr[st], arr[en]);
			st++;
			en--;
			ans++;
		}
	}


	return 0; 
}