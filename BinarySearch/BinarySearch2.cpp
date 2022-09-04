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

// N개 크기 배열을 이진 탐색하면 N N/2 N/4 N/8 ... 1
// 여기서 실행된 탐색의 횟수가 시간 복잡도 
// 그 값을 K 
// K는 N에 대해 어떻게 나타낼 수 있을까?
// 1에 2를 K번 곱하면? N이 된다.
// 2^K = N 
// K = log2N
// 즉 이진 탐색의 시간 복잡도는 OlogN