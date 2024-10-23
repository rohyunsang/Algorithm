#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int Find(int x) {
	if (parent[x] != x) parent[x] = Find(parent[x]);
	return parent[x];
}

void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	parent[y] = x;
	return;
}

bool SameParent(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return true;
	else return false;
}


int main() {
	int n, m;
	cin >> n >> m;

	int ans = 0;
	
	vector<pair<int, int>> graph;
	
	parent.resize(n);

	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	bool flag = false;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		if (SameParent(x, y) == false) {
			Merge(x, y);
			ans++;
		}
		else {
			cout << ans + 1;
			flag = true;
			return 0;
		}
	}

	if (flag == false)
		cout << 0;




	return 0;
}


// 같은 부모를 가지고 있는 두 노드를 연결하려고 할 때 사이클이 발생한다. 