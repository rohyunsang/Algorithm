#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m;

int main() {

	int n;
	cin >> n;
	
	vector<int> v;
	vector<int> vOrigin;

	for (int i = 0; i < n; i++) {
		int nTmp;
		cin >> nTmp;

		v.push_back(nTmp);
	}
	vOrigin = v;

	sort(v.begin(), v.end());
	int idx = 0;
	for (int i = 0; i < v.size(); i++) {
		if (m.count(v[i]) == 0) { // count�� map�� ���Ұ� �ִ��� ������ Ȯ�� �����ϴ�. 
			m[v[i]] = idx;
			idx++;
		}
	}
	
	for (int i = 0; i < vOrigin.size(); i++) {
		cout << m[vOrigin[i]] << " ";
	}

	return 0;
}