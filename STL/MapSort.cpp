#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, string> m;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
	return a.second < b.second;
}

void sort(map<string, int>& map) {
	vector<pair<string, int>> vec;

	for (auto& it : map) {
		vec.emplace_back(it);
	}

	sort(vec.begin(), vec.end());
	for (auto& it : vec) {
		cout << it.first << " " << it.second << endl;
	}

}

#include <iostream>
#include <string>
#include <map>
#include <vector>

// 코드 단순화 (귀차니즘..)
#define pp pair<string, int>
#define mm map<string, int>

using namespace std;

// 사용자 정의 비교함수
bool cmp(const pair<string, int>& a,
	const pair<string, int>& b)
{
	return a.second < b.second;
}

// sort 담당함수
void sort(const map<string, int>& map)
{
	vector<pair<string, int>> vec;

	for (auto& it : map) {
		vec.push_back(it);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (auto& it : vec) {
		cout << " 할일 " << it.first << " 중요도 : " << it.second << endl;
	}
}

int main()
{
	mm todo = {
		{"블로깅", 3},
		{"프로그래밍", 1},
		{"운동", 2}
	};
	sort(todo);
}

