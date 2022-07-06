#include <bits/stdc++.h>

using namespace std;

// N : 집의 개수 2 ~100,000
// M : 길의 개수 1 ~100,000
// A B : House
// C : Cost

int v, e;
int parent[100001];

vector<pair<int, pair<int, int> > > edges;
