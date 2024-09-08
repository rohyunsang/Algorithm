#include <iostream>
#include <vector>

using namespace std;

#define MAX 2123456789; // MAX 2123456789 로 설정하기. 

int main() {
	int n;
	cin >> n;

	vector<int> v;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int min = MAX;
	int leftPointer = 0;
	int rightPointer = 0;
	int start = 0;
	int end = (int)v.size() - 1;

	while (start < end) {

		int cur = v[start] + v[end];

		if (min > abs(cur)) {
			min = abs(cur);
			leftPointer = start;
			rightPointer = end;
		}
		if (cur < 0) {
			start++;
		}
		else if(cur > 0){
			end--;
		}
		else {
			break;
		}
	}

	cout << v[leftPointer] << " " << v[rightPointer];


	return 0;
}