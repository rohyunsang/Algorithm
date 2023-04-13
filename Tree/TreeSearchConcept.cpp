#include <iostream>

using namespace std;

int n;

char tree[26][2];

void PreOrder(char root) {
	if (root == '.')
		return;
	cout << root;
	PreOrder(tree[root - 'A'][0]);
	PreOrder(tree[root - 'A'][1]);
}
void InOrder(char root) {
	if (root == '.') return;
	InOrder(tree[root - 'A'][0]);
	cout << root;
	InOrder(tree[root - 'A'][1]);
}
void PostOrder(char root) {
	if (root == '.') return;
	PostOrder(tree[root - 'A'][0]);
	PostOrder(tree[root - 'A'][1]);
	cout << root;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c;
		cin >> a >> b >> c;
		tree[a - 'A'][0] = b;
		tree[a - 'A'][1] = c;
	}



	return 0;
}