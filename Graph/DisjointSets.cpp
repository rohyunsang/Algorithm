#include <bits/stdc++.h>
using namespace std;

// 더 큰 노드가 더 작은 노드를 가리키게 하면 된다!

int v, e;
int parent[100001];

int findParent(int x) {
	if (x == parent[x]) return x;
	return findParent(parent[x]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main(void) {
	cin >> v >> e;

	for (int i = 0; i <= v; i++)
	{
		int a, b;
		cin >> a >> b;
		unionParent(a, b);
	}

	cout << "각 원소가 속한 집합 : ";
	for (int i = 0; i <= v; i++)
	{
		cout << findParent(i) << ' ';
	}
	cout << '\n';

	cout << "부모 테이블 : ";
	for (int i = 0; i <= v; i++)
	{
		cout << parent[i] << ' ';
	}
	cout << '\n';
}

