#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const int& a, const int& b)
{
	if (a > b)
		return true;
	else
		return false;
}

int arr[10] = { 12,5,2,15,21,5,61,6,1,7 };
int main() {
	for (auto arr : arr) {
		cout << arr << " ";
	}
	cout << endl;

	sort(arr, arr + 10);

	for (auto arr : arr) {
		cout << arr << " ";
	}
	cout << endl;

	sort(arr, arr + 10, compare);

	for (auto arr : arr) {
		cout << arr << " ";
	}
	cout << endl;

	return 0;
}

/* Console: 12 5 2 15 21 5 61 6 1 7
			 2 5 5 6 7 12 15 21 61
			61 21 15 12 7 6 5 5 2 1 */