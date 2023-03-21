#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;

// 1 second x-1 or x+1 or 2x 
const int MAX = 100000 + 1;
int map[MAX] = { -1, };
bool visited[MAX] = { false, };

queue<pair<int, int>> q;
vector<int> path;

int SearchMap(int n, int k) {
	q.push({ n,k });
	visited[n] = true;

	while (!q.empty()) {
		int curPos = q.front().first;
		int curSec = q.front().second;
		q.pop();

		if (curPos = k) { 
			int idx = curPos;
			while (idx != n) {
				path.push_back(idx);
				idx = map[idx];
			}
			path.push_back(n);
			return curPos;
		}

		if (curPos + 1 < MAX && !visited[curPos + 1])
		{
			q.push({ curPos + 1,curSec + 1 });
			visited[curPos + 1] = true;
			map[curPos + 1] = curPos;
		}
		if (curPos - 1 >= 0 && !visited[curPos - 1]) {
			q.push({ curPos - 1 ,curPos + 1 });
			visited[curPos - 1] = true;
			map[curPos - 1] = curPos;
		}
		if (curPos * 2 < MAX && !visited[curPos * 2]) {
			q.push({ curPos * 2,curSec + 1 });
			visited[curPos * 2] = true;
			map[curPos * 2] = curPos;
		}
	}
}

int main() {
	cin >> n >> k;
	map[n] = 0;

	cout << SearchMap(n, k) << endl;

	for (int i = path.size() - 1; i >= 0; i--) {
		cout << path[i] << ' ';
	}

	return 0;
}