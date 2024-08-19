#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int solution(vector<int> sid, vector<int> sid_first) {

	int ans = 0;
	int roomCnt = (sid.size() + 3) / 4;  // 4��� �� 1��

	priority_queue<int, vector<int>, greater<int>> pq_first;  // ���� pq�� ��������, �̰��� �������� 
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
		

		// �濡 4�� ���� (�ִ� 2�� 1��, ������ 2���� �ƹ� ���̳�)
		// 1�� ħ�� �켱 ����
		while (!pq_any.empty() && !pq_first.empty() && pq_first.top() < pq_any.top() && students_in_room < 4 && first_floor_assigned < 2) {
			pq_first.pop();
			first_floor_assigned++;
			students_in_room++;
			ans++;  // 1�� ħ�� ������ �л� �� ����
		}

		// ���� �ڸ����� �ƹ� ���̳� ������� �л� ����
		while (students_in_room < 4 && !pq_any.empty()) {
			pq_any.pop();
			students_in_room++;
		}

		// ���� �ڸ����� 1���� �������� �������� ���� �л��� 2�� ħ��� ����
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
	cout << "Test Case 1: " << solution(sid1, sid_first1) << endl;  // ���� ���: 4

	// �׽�Ʈ ���̽� 2: 1�� ħ�븦 ���ϴ� �л��� ���� ���
	vector<int> sid2 = { 19283922, 20283922, 21283922, 22282922, 23283922, 24283922, 25283922, 26283922 };
	vector<int> sid_first2;  // 1���� ���ϴ� �л��� ����
	cout << "Test Case 2: " << solution(sid2, sid_first2) << endl;  // ���� ���: 0

	// �׽�Ʈ ���̽� 3: ��� �л��� 1�� ħ�븦 ���ϴ� ���
	vector<int> sid3 = { 19283922, 20283922, 21283922, 22282922 };
	vector<int> sid_first3 = { 19283922, 20283922, 21283922, 22282922 };  // ��� 1���� ����
	cout << "Test Case 3: " << solution(sid3, sid_first3) << endl;  // ���� ���: 2

	// �׽�Ʈ ���̽� 4: �й��� ���� ��� (1���� ���ϳ�, �й��� �ڼ���)
	vector<int> sid4 = { 1, 2, 3, 4, 5, 6, 7, 8 };
	vector<int> sid_first4 = { 3, 4, 7, 8 };  // �й��� ����
	cout << "Test Case 4: " << solution(sid4, sid_first4) << endl;  // ���� ���: 2

	// �׽�Ʈ ���̽� 5: �л� ���� �濡 �� ���� �ʴ� ���
	vector<int> sid5 = { 1, 2, 3 };  // 3�� ����
	vector<int> sid_first5 = { 1 };  // 1���� 1���� ����
	cout << "Test Case 5: " << solution(sid5, sid_first5) << endl;  // ���� ���: 1

	vector<int> sid6 = { 19283922, 20283922, 21283922, 22282922, 23283922 };
	vector<int> sid_first6;  // �ƹ��� 1�� ħ�븦 ������ ����
	cout << "Test Case 6: " << solution(sid6, sid_first6) << endl;  // ���� ���: 0


	vector<int> sid7 = { 19283922 };  // �� ���� �л��� ����
	vector<int> sid_first7 = { 19283922 };  // �� �� ���� 1���� ����
	cout << "Test Case 9: " << solution(sid7, sid_first7) << endl;  // ���� ���: 1

	return 0;
}

