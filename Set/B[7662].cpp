#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		multiset<int> ms;
		
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			char c;
			int x;
			cin >> c >> x;
			if (c == 'I')
			{
				ms.insert(x);
			}
			else if (c == 'D' && !ms.empty()) {
				if (x == 1) {
					auto iter = prev(ms.end()); // 주어진 반복자를 지정된 수만큼 뒤로 이동시킴
					ms.erase(iter);
				}
				else if (x == -1) {
					ms.erase(ms.begin());
				}
			}
		}
		if (ms.empty()) {
			cout << "EMPTY" << endl;
		}
		else {
			cout << *prev(ms.end()) << " " << *ms.begin() << endl;
		}
	}
	

	return 0;
}