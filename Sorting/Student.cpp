#include <bits/stdc++.h>

using namespace std;

int N; //(1<= N <= 100,000)

class Student {
public: 
	string name;
	int score;
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}

	bool operator <(Student& other) {
		return this->score < other.score;
	}
};

vector<Student> v;

int main() {
	// 
	cin >> N;

	for (int i = 0; i < N; i++) {
		string name;
		int score;
		cin >> name >> score;
		v.push_back(Student(name, score));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i].name << ' ';
	}
}