#include <bits/stdc++.h>

using namespace std;

int v, e;
int parent[100001]; // save there's parents in array 

//Find Union Parent

int findParent(int x)
{
	if (x == parent[x]) return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;

}
