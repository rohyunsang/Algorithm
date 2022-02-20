#include <bits/stdc++.h>

using namespace std;

//dfs

vector<int> arr[101];
int N, M;
int cnt = 0;
bool isCheck[101];


void dfs(int x) {
	isCheck[x] = true;

	for (int i = 0; i < arr[x].size(); i++) {
		int y = arr[x][i];
		if (!isCheck[y]) {
			cnt++;
			dfs(y);
		}
	}
}

int main() {

	cin >> N >> M; //N : Node M : Edge

	for (int i = 0; i < M; i++)
	{
		int x;
		int y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	dfs(1);  //only connection graph 1 

	cout << cnt;

	return 0;
}

//https://www.acmicpc.net/problem/2606