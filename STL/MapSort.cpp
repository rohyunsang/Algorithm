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

// �ڵ� �ܼ�ȭ (��������..)
#define pp pair<string, int>
#define mm map<string, int>

using namespace std;

// ����� ���� ���Լ�
bool cmp(const pair<string, int>& a,
	const pair<string, int>& b)
{
	return a.second < b.second;
}

// sort ����Լ�
void sort(const map<string, int>& map)
{
	vector<pair<string, int>> vec;

	for (auto& it : map) {
		vec.push_back(it);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (auto& it : vec) {
		cout << " ���� " << it.first << " �߿䵵 : " << it.second << endl;
	}
}

int main()
{
	mm todo = {
		{"��α�", 3},
		{"���α׷���", 1},
		{"�", 2}
	};
	sort(todo);
}

