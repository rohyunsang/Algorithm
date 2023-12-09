#include <iostream>
#include <algorithm>

using namespace std;

void dfs(int cnt, int idx) { // ��������� ���, Ž���� ������ �ε��� 
	// r���� ������ ��� 
	if (cnt == r) {
		// ��� ó�� �� ���� ������ ���� Ž�� ���� 
		return;
	}

	// r���� �������� ���� ��� ��� ȣ�� �ݺ� 
	for (int i = idx; i < n; i++) {
		if (!selected[i]) {
			selected[i] = true; // ���� ��ȭ 
			dfs(cnt + 1, i); // ��� ȣ��
			selected[i] = false; // ���� ����� ���� ���� ���� ���� 
		}
	}
}