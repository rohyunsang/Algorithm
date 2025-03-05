#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> minSegTree;
vector<int> maxSegTree;

#define MAX 2123456789
#define MIN 0

int Init(int start, int end, int node) {
	if (start == end)
		return minSegTree[node] = v[start];
	int mid = (start + end) / 2;

	return minSegTree[node] = min(Init(start, mid, node * 2), Init(mid + 1, end, node * 2 + 1));
}

// @overload
int Init(int start, int end, int node, int trashOverride) {
	if (start == end)
		return maxSegTree[node] = v[start];
	int mid = (start + end) / 2;

	return maxSegTree[node] = max(Init(start, mid, node * 2, 0), Init(mid + 1, end, node * 2 + 1, 0));
}


int query(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return MAX;

	if (left <= start && end <= right) return minSegTree[node];

	int mid = (start + end) / 2;
	return min(query(start, mid, 2 * node, left, right), query(mid + 1, end, 2 * node + 1, left, right));
}

// @overload
int query(int start, int end, int node, int left, int right, int trashOverride) {
	if (left > end || right < start) return MIN;

	if (left <= start && end <= right) return maxSegTree[node];

	int mid = (start + end) / 2;
	return max(query(start, mid, 2 * node, left, right, 0), query(mid + 1, end, 2 * node + 1, left, right, 0));
}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	v.push_back(0);  // segtree offset 
	minSegTree.resize(4 * n);
	maxSegTree.resize(4 * n);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	Init(1, n, 1);
	Init(1, n, 1, 0);

	for (int i = 0; i < m; i++) {
		int st, en;
		cin >> st >> en;
		cout << query(1, n, 1, st, en) << ' ';
		cout << query(1, n, 1, st, en, 0) << '\n';
	}



	return 0;
}