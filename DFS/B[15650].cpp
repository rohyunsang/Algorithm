#include <iostream>

using namespace std;

int n, targetDepth;
int arr[9];
bool isVisited[9];


void dfs(int depth, int idx) {
	if (depth == targetDepth) {  // 깊이가 같아지면
		for (int i = 0; i < n; i++) {
			if (isVisited[i]) {
				cout << arr[i] << " ";
			}
		}
		cout << endl;
		return;
	}
	for (int i = idx; i < n; i++) { // 깊이가 다를경우 dfs로 목표 깊이까지 내려감 
		if (isVisited[i]) continue;
		isVisited[i] = true;
		dfs(depth + 1, i + 1);
		isVisited[i] = false;
	}
}

int main() {
	cin >> n >> targetDepth;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
		isVisited[i] = false;
	}

	dfs(0, 0);

	return 0;
}
