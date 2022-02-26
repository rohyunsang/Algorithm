#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;

	vector<int> v;
	vector<int> v1(5); //0으로 초기화, 원소 5개
	vector<int> v2(10, 2); // 2로 초기화, 원소 10개
	v.assign(5, 7); //NewSize, Const int & _Val

	v.push_back(n);
	v.pop_back();
	v.clear(); //size = 0 but remain capacity.

	v.insert(v.begin(), 5);

	v.at(1); //n번째 원소를 참조

	v.size(); //원소의 갯수 
	v.capacity();
	v.resize(n); //크기를 n으로 변경한다.

	v.begin(); //첫번째 원소를 가리킨다.
	v.end();

	v.front(); //첫번쨰 원소를 참조한다.
	v.back();

	v.erase(v.begin());
	v.erase(v.begin() + 1);
	v.erase(v.begin(), v.end()); 
	//v.erase(v.front()); error
	
	return 0;
}
