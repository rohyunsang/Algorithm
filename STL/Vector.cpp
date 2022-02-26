#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;

	vector<int> v;
	vector<int> v1(5); //0���� �ʱ�ȭ, ���� 5��
	vector<int> v2(10, 2); // 2�� �ʱ�ȭ, ���� 10��
	v.assign(5, 7); //NewSize, Const int & _Val

	v.push_back(n);
	v.pop_back();
	v.clear(); //size = 0 but remain capacity.

	v.insert(v.begin(), 5);

	v.at(1); //n��° ���Ҹ� ����

	v.size(); //������ ���� 
	v.capacity();
	v.resize(n); //ũ�⸦ n���� �����Ѵ�.

	v.begin(); //ù��° ���Ҹ� ����Ų��.
	v.end();

	v.front(); //ù���� ���Ҹ� �����Ѵ�.
	v.back();

	v.erase(v.begin());
	v.erase(v.begin() + 1);
	v.erase(v.begin(), v.end()); 
	//v.erase(v.front()); error
	
	return 0;
}
