#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int solution(vector<int> sid, vector<int> sid_first) {

	int ans = 0;
	int roomCnt = (sid.size() + 3) / 4;  // 4명당 방 1개

	priority_queue<int, vector<int>, greater<int>> pq_first;  // 기존 pq는 내림차순, 이것은 오름차순 
	priority_queue<int, vector<int>, greater<int>> pq_any;

	sort(sid.begin(), sid.end());
	sort(sid_first.begin(), sid_first.end());

	map<int, int> m;
	for (int i = 0; i < sid.size(); i++) {
		if (!sid.empty())
			m[sid[i]]++;
	}
	for (int i = 0; i < sid_first.size(); i++) {
		if (!sid_first.empty())
			m[sid_first[i]]++;
	}

	for (const auto m : m) {
		if (m.second > 1)
		{
			pq_first.push(m.first);
		}
		else {
			pq_any.push(m.first);
		}
	}

	while (roomCnt--) {
		int students_in_room = 0;
		int first_floor_assigned = 0;
		

		// 방에 4명 배정 (최대 2명 1층, 나머지 2명은 아무 층이나)
		// 1층 침대 우선 배정
		while (!pq_any.empty() && !pq_first.empty() && pq_first.top() < pq_any.top() && students_in_room < 4 && first_floor_assigned < 2) {
			pq_first.pop();
			first_floor_assigned++;
			students_in_room++;
			ans++;  // 1층 침대 배정된 학생 수 증가
		}

		// 남은 자리에는 아무 층이나 상관없는 학생 배정
		while (students_in_room < 4 && !pq_any.empty()) {
			pq_any.pop();
			students_in_room++;
		}

		// 남은 자리에는 1층을 원했지만 배정되지 못한 학생을 2층 침대로 배정
		while (students_in_room < 4 && !pq_first.empty()) {
			pq_first.pop();
			students_in_room++;
			if (first_floor_assigned < 2) {
				first_floor_assigned++;
				ans++;
			}
		}
	}


	return ans;
}

int main() {
	vector<int> sid1 = { 19283922, 20283922, 21283922, 22282922, 23283922, 24283922, 25283922, 26283922 };
	vector<int> sid_first1 = { 20283922, 19283922, 23283922, 24283922, 26283922 };
	cout << "Test Case 1: " << solution(sid1, sid_first1) << endl;  // 예상 출력: 4

	// 테스트 케이스 2: 1층 침대를 원하는 학생이 없는 경우
	vector<int> sid2 = { 19283922, 20283922, 21283922, 22282922, 23283922, 24283922, 25283922, 26283922 };
	vector<int> sid_first2;  // 1층을 원하는 학생이 없음
	cout << "Test Case 2: " << solution(sid2, sid_first2) << endl;  // 예상 출력: 0

	// 테스트 케이스 3: 모든 학생이 1층 침대를 원하는 경우
	vector<int> sid3 = { 19283922, 20283922, 21283922, 22282922 };
	vector<int> sid_first3 = { 19283922, 20283922, 21283922, 22282922 };  // 모두 1층을 원함
	cout << "Test Case 3: " << solution(sid3, sid_first3) << endl;  // 예상 출력: 2

	// 테스트 케이스 4: 학번이 섞인 경우 (1층을 원하나, 학번이 뒤섞임)
	vector<int> sid4 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> sid_first4 = { 3, 4, 7, 8 };  // 학번이 섞임
	cout << "Test Case 4: " << solution(sid4, sid_first4) << endl;  // 예상 출력: 2

	// 테스트 케이스 5: 학생 수가 방에 꽉 차지 않는 경우
	vector<int> sid5 = { 1, 2, 3 };  // 3명만 있음
	vector<int> sid_first5 = { 1 };  // 1명이 1층을 원함
	cout << "Test Case 5: " << solution(sid5, sid_first5) << endl;  // 예상 출력: 1

	vector<int> sid6 = { 19283922, 20283922, 21283922, 22282922, 23283922 };
	vector<int> sid_first6;  // 아무도 1층 침대를 원하지 않음
	cout << "Test Case 6: " << solution(sid6, sid_first6) << endl;  // 예상 출력: 0


	vector<int> sid7 = { 19283922 };  // 한 명의 학생만 존재
	vector<int> sid_first7 = { 19283922 };  // 그 한 명이 1층을 원함
	cout << "Test Case 9: " << solution(sid7, sid_first7) << endl;  // 예상 출력: 1

	return 0;
}

