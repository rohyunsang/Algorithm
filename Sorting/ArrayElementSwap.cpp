#include <bits/stdc++.h>

using namespace std;

int N, K; //(1<= N <= 100,000, 0 <= K <= N)

vector<int> A;
vector<int> B;

bool comp(int x, int y) {
	return x > y;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A.push_back(x);
	}

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		B.push_back(x);
	}

	sort(A.begin(), A.end()); 
	sort(B.begin(), B.end(), comp);
	
	for (int i = 0; i < K; i++)
	{
		if (A[i] < B[i]) {
			swap(A[i], B[i]);
		}
		else break;
	}
	
	long long sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum = sum + A[i];
	}

	return 0;
}