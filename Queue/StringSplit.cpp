#include <queue>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s, int n) {
	priority_queue<int> pq;

	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		int cnt = 1;
		for (int j = i + 1; j < s.size(); j++) {
			if (c == s[j]) {
				cnt++;
			}
			else {
				break;
			}
		}
		pq.push(cnt);
		i += cnt; // 현재 그룹의 크기만큼 인덱스를 건너뜀 
	}
	

	for(int i = 0; i < n ;i++){
		int pqTop = pq.top();
		pq.pop();
		if (pqTop == 1)
			break;
		if (pqTop % 2 == 0) {
			pq.push(pqTop / 2);
			pq.push(pqTop / 2);
		}
		else {
			pq.push(pqTop / 2);
			pq.push((pqTop / 2) + 1);
		}		
	}

	if (pq.top() >= 1)
	{
		return pq.top();
	}
	else {
		return 1;
	}
}

int main() {

	// test case 
	cout << solution("abaabbbacdedqdwqe", 4);
	cout << solution("abaabbbac", 3);
	cout << solution("abcd", 2);
	cout << solution("abcbbbbbbbbbbbbbd", 2);

	return 0;
}


