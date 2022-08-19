#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int N; // 1 <= N <= 100,000


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		if (tmp == 0)
		{
			if (pq.empty()) {
				cout << 0 <<"\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(tmp);
		}
	}
	
	
	return 0;
}


// 시간초과 endl 대신에 "\n" 사용하기
