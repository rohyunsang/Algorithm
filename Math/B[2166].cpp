#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // fabs

using namespace std;

vector<pair<int, int>> points;


long double Cal(int x, int y) {
	long double a = points[0].first;
	long double b = points[0].second;
	long double c = points[x].first;
	long double d = points[x].second;
	long double e = points[y].first;
	long double f = points[y].second;
	
	return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main() {
	long double ans = 0;

	int n;
	cin >> n;


	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		points.push_back({ x,y });
	}

	for (int i = 1; i < n - 1; i++) {
		ans += Cal(i, i + 1);
	}

	cout << fixed;
	cout.precision(1);
	cout << fabs(ans);



	return 0; 
}