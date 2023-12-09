#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int cnt, int idx) { // 현재까지의 결과, 탐색을 진행할 인덱스 
	// r개를 선택한 경우 
	if (cnt == r) {
		// 결과 처리 후 현재 가지에 대한 탐색 종료 
		return;
	}

	// r개를 선택하지 않은 경우 재귀 호출 반복 
	for (int i = idx; i < n; i++) {
		if (!selected[i]) {
			selected[i] = true; // 상태 변화 
			dfs(cnt + 1, i); // 재귀 호출
			selected[i] = false; // 다음 경우의 수를 위해 상태 복구 
		}
	}
}