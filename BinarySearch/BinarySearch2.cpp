#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int BinarySearch(const vector<int>& v, int target) {
	int low = 0;
	int high = v.size() - 1;
	int mid;

	while (low <= high) {
		mid = (low + high) / 2;

		if (v[mid] == target)
			return mid;
		else if (v[mid] > target)
			high = mid - 1;
		else
			low = mid + 1;
	}

	return -1;
}

int main() {


	return 0;
}

// N�� ũ�� �迭�� ���� Ž���ϸ� N N/2 N/4 N/8 ... 1
// ���⼭ ����� Ž���� Ƚ���� �ð� ���⵵ 
// �� ���� K 
// K�� N�� ���� ��� ��Ÿ�� �� ������?
// 1�� 2�� K�� ���ϸ�? N�� �ȴ�.
// 2^K = N 
// K = log2N
// �� ���� Ž���� �ð� ���⵵�� OlogN