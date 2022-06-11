#include <bits/stdc++.h>
using namespace std;

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

	cout << "�� ���Ұ� ���� ���� : ";
	for (int i = 0; i <= v; i++)
	{
		cout << findParent(i) << ' ';
	}
	cout << '\n';

	cout << "�θ� ���̺� : ";
	for (int i = 0; i <= v; i++)
	{
		cout << parent[i] << ' ';
	}
	cout << '\n';
}

