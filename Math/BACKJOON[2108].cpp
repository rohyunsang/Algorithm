#include <iostream>
#include <vector>
#include <cmath> //round ¹Ý¿Ã¸² function
#include <algorithm> 
using namespace std;

int n;
vector<int> v;
int arr[8001];


int main() {
	int index = 0;
	int max = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);

		if (tmp <= 0)
			index = -tmp;
		else
			index = 4000 + tmp;

		arr[index]++;

		if (arr[index] > max)
			max = arr[index];
	}
	////////////////////////////////////////
	// »ê¼úÆò±Õ
	int sum = 0;
	for (auto& v : v) {
		sum += v;
	}
	double result;
	result = (double)sum / v.size();
	if (result <0 && result > -0.5)
		result = 0;
	cout << round(result) << endl;

	///////////////////////////////////////
	//Áß¾Ó°ª
	sort(v.begin(), v.end());
	result = v[round(v.size() / 2)];
	cout << result << endl;

	///////////////////////////////////////
	//ÃÖºó°ª
	bool flag = false;
	int answer = 0;

	for (int i = -4000; i < 4001; i++) {
		if (i <= 0)
			index = -i;
		else
			index = 4000 + i;

		if (arr[index] == max) {
			answer = i;
			if (flag)
				break;
			flag = true;
		}
		
	}

	cout << answer << endl;

	///////////////////////////////////////
	//¹üÀ§
	result = v.back() - v[0]; //v.back() - v.front()
	cout << result << endl;




	return 0;
}