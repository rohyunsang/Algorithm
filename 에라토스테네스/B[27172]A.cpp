#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> nums;

#define MAX 1000006

int scores[MAX];
map<int, int> cards;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		nums.push_back(temp); 
		cards[temp]++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = nums[i] * 2; j < MAX; j += nums[i])
		{
			if (cards[j] == 1)
			{
				scores[nums[i]]++;
				scores[j]--;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << scores[nums[i]] << " ";

	return 0;
}