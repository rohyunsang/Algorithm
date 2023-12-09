#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// Combination -> BackTracking

vector<char> c;
int n, m;
bool isVisit[15] = { false, };

bool isVowel(char cha) {
	if (cha == 'a' || cha == 'e' || cha == 'i' || cha == 'o' || cha == 'u')
		return true;
	else
		return false;
}

void dfs(int cur, int cntVowel, int cntConso, string pwd) {
	
	if ((int)pwd.size() == n) {
		if (cntVowel >= 1 && cntConso >= 2) {
			cout << pwd << '\n';
		}
		return;
	}
	if (cur >= m) {
		return;
	}
	
	isVisit[cur] = true;
	if (isVowel(c[cur])) { // ���� ����
		dfs(cur + 1, cntVowel + 1, cntConso, pwd + c[cur]);
	}
	else { // ���� ���� 
		dfs(cur + 1, cntVowel, cntConso + 1, pwd + c[cur]);
	}

	// ���� ���ڸ� �������� �ʴ� ���.
	isVisit[cur] = false;
	dfs(cur + 1, cntVowel, cntConso, pwd);
	

}

int main() {

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char cTmp;
		cin >> cTmp;
		c.push_back(cTmp);
	}

	sort(c.begin(), c.end());

	dfs(0, 0, 0, "");

	return 0;
}