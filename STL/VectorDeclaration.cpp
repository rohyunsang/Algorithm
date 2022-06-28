#include <bits/stdc++.h>

using namespace std;

vector<int> graph;

vector<int> graph2[101];

vector<int> graph3(101);

int main() {
	int now = 1;

	graph.push_back(1);
	graph.push_back(2);
	graph.push_back(3);

	graph2[50].push_back(10);
	graph2[50].push_back(20);
	graph2[50].push_back(30);

	graph3.push_back(100);
	graph3.push_back(200);
	graph3.push_back(300);

	cout << graph[0] << endl;
	cout << graph[1] << endl;
	cout << graph[2] << endl;

	cout << graph2[50][0] << endl;
	cout << graph2[50][1] << endl;
	cout << graph2[50][2] << endl;

	cout << graph3[101] << endl;
	cout << graph3[102] << endl;
	cout << graph3[103] << endl;

	return 0;
}