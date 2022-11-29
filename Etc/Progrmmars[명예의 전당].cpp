#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
	vector<int> answer;
	vector<int> tmp;
	for (int i = 0; i < score.size(); i++) {
		tmp.push_back(score[i]);
		sort(tmp.begin(), tmp.end());
		if (i < k) {
			answer.push_back(*min_element(tmp.begin(), tmp.end()));
		}
		else
			answer.push_back(tmp[tmp.size() - k]);
	}
	

	return answer;
}

int main() {


	return 0;
}