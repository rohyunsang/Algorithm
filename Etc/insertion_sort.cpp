#include <iostream>

using namespace std;

void insertion_sort(int list[], int n) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = list[i];

		for (j = i - 1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}

		list[j + 1] = key;
	}
}

void main() {
	int i;
	const int n = 5;
	int list[n] = { 8,5,6,2,4 };

	insertion_sort(list, n);

	for (const auto& list : list) {
		cout << list;
	}

}

// insertion sort time complexity
// �ּ��� ��� : n-1 O(n)
// �־��� ��� : n-1 + n-2 + n-3 + ... + 2 + 1 = n(n-1)/2 = O(n^2)
