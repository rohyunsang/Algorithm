#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

	int n;
	cin >> n;

	vector<int> A;
	vector<int> B;
	vector<int> C;
	vector<int> D;

	vector<int> X;
	vector<int> Y;

	for (int i = 0; i < n; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			X.push_back(A[i] + B[j]);
			Y.push_back(C[i] + D[j]);
		}
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());

	long long ans = 0;

	for (int i = 0; i < (int)X.size(); i++)
	{
		int pre = lower_bound(Y.begin(), Y.end(), -X[i]) - Y.begin();
		int end = upper_bound(Y.begin(), Y.end(), -X[i]) - Y.begin();

		ans += end - pre;
	}

	cout << ans;
	
}

// O(N^4) 
// Idea 
// C�� D �迭�� ����� �������� ���� ���� ���ο� �迭 �����. 
// A�� B �迭�� ����� �������� ���� ���� ���ο� �迭 �����. 
