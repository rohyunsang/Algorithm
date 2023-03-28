#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int ans = 0;

int ConvertToInt(string s, bool isEndTime) {
	int hour = stoi(s.substr(0, 2));
	int minute = stoi(s.substr(3, 2));

	if (isEndTime) {
		if (minute >= 50) {
			hour += 1;
			minute -= 50;
		}
		else
			minute += 10;
	}
	return hour * 100 + minute;
}

int solution(vector<vector<string>> book_time) {
	vector<pair<int, int>> v;

	for (const auto t : book_time) {
		int start = ConvertToInt(t[0], false);
		int end = ConvertToInt(t[1], false);

		v.push_back({ start,end });
	}

	sort(v.begin(), v.end());

	vector<pair<int, int>> filled;

	for (const auto t : v) {
		int start = t.first;
		vector<pair<int, int>> temp;

		for (pair<int, int> room : filled) {
			if (start < room.second)
				temp.push_back(room);
		}

		filled = temp;
		filled.push_back(t);
		ans = max(ans, (int)filled.size()); 

	}

	return ans;
}