#include <iostream>

using namespace std;

int n;
// 256(245 + 2 + 4 + 5) 245�� 256�� ������ 

int main() {

	ios::sync_with_stdio(false);
	

	int sum = 0;
	int div = 0;
	cin >> n;
	for (int i = 1; i < n; i++) {
		sum = i;
		div = i;

		while (div) {
			sum += div % 10;
			div /= 10;
		}

		if (n == sum) {
			cout << i << endl;
			return 0;
		}
	}
	// �����ڰ� ���� ��쿡�� 0�� ����Ѵ�.
	cout << 0 << endl;

	return 0;
}