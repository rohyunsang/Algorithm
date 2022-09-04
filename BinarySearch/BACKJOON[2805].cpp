#include <iostream>
#include <vector>
#include <algorithm>
//Binary Search 

using namespace std;


int n, m;// n <= 1,000,000 m <= 2,000,000,000

//int arr[1000000 + 1]; //auto init elemets have 0
vector<int> v;

int binarySearch(const vector<int> &v) {

	int start = 0;
	int end = *max_element(v.begin(), v.end()); // v *max_element
	int result = 0;

	while (start <= end) {
		long long int total = 0;
		int mid = (start + end) / 2;
		for (int i = 0; i < n; i++)
		{
			if (v[i] > mid) {
				total += v[i] - mid;
			}
		}
		if (total < m) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}


	return result;
}


int main() {

	cin >> n >> m;
	for (auto i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}



	cout << binarySearch(v);

	return 0;
}

// optimization problem => first imagine bianry search