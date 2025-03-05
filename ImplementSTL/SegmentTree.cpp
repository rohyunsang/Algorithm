// Segment Tree
// ���� ���� �����Ͱ� ���������� ������ �� Ư���� ������ �������� ���� ���ϴ� ���
// ���׸�Ʈ Ʈ���� �̿��ϸ� ���� �� ���ϱ�, ������ O(log N)���� ó�� ����

#include <iostream>
#include <vector>
#define NUMBER 12

using namespace std;

int a[] = { 1,9,3,8,4,5,5,9,10,3,4,5 };
int tree[4 * NUMBER]; // 4�� ���ϸ� ��� ������ Ŀ���� �� ����. 
// ������ ���ؼ� 2�� ���� ������ ���̸� ������ ������.


int Init(int start, int end, int node) {
	if (start == end) return tree[node] = a[start];
	int mid = (start + end) / 2;
	return tree[node] = Init(start, mid, node * 2) + Init(mid + 1, end, node * 2 + 1);
}

int sum(int start, int end, int node, int left, int right) {

	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, int dif) {
	if (index < start || index > end) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}


