#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100000 + 1

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int answer = 0;

		vector<pair<int, int>> v;

		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}

		sort(v.begin(), v.end()); 
		// 성적 "순위" 여서 중복이 없다. 
		// 성적은 낮을수록(1에 가까울수록 좋다.)

		/*
		for (auto v : v) {
			cout << v.first << " " <<  v.second << " " << endl;
		}
		*/
		int minSecond = MAX;
			
		for (int i = 0; i < n; i++) {
			if (v[i].second < minSecond) {
				answer++;
				minSecond = min(minSecond, v[i].second);
			}
		}
		cout << answer << endl;
	}

	return 0;
}