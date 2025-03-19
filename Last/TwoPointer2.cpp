#include <iostream>
#include <vector>

using namespace std;

int main() {

	int guilder_count = 2;
	int k = 3;
	vector<int> score = { 8,21,8,15,5,30,21 };

	int ans = 0;

	while (guilder_count--)
	{
		pair<int, int> max = { -1,-1 }; // idx, value 
		int st = 0;
		int en = (int)score.size() - 1;
		int l_cnt = k;
		int r_cnt = k;

		while (l_cnt > 0 && r_cnt > 0)
		{
			if (l_cnt > 0)
			{
				if (score[en] == -987654321)
				{
					en--;
					continue;
				}

				if (score[en] >= max.second)
				{
					max = { en,score[en] };
					en--;
					
				}
				l_cnt--;
			}
			
			if (r_cnt > 0)
			{

				if (score[st] == -987654321)
				{
					st++;
					continue;
				}

				if (score[st] > max.second)
				{
					max = { st,score[st] };
					st++;
				}
				r_cnt--;
			}
		}
		ans += max.second;
		score[max.first] = -987654321;
	}

	cout << ans;

	return 0;
}