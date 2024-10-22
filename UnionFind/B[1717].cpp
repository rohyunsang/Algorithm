#include <iostream>
#include <vector>

using namespace std;

int parent[1000000 + 1];

int find(int x) {
	if (parent[x] == x)
		return x;
	else {
		parent[x] = find(parent[x]);
		return parent[x];
	}
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}


	for (int i = 0; i < m; i++) {
		int command, a, b;
		cin >> command >> a >> b;

		if (command == 0) {  // Union
			merge(a, b);
		}
		if (command == 1) {  // Same Set? 
			if (find(a) == find(b)) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}


	return 0;
}