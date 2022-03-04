#include <bits/stdc++.h>
using namespace std;
using namespace vector;
int n,m;
vector<int> v;

int main() {
    
    for(int i = 0 ; i< n ; i++)
    {
        int x;
        cin >>x;
        v.push_back(x);
    }
    
    vector<int> d(m + 1, 10001); //Data table
    
    d[0] = 0;
    for(int i=0; i<n;i++){
        for(int j = v[i]; j<=m;j++){
            if(d[j-v[i]] != 10001){
                d[j] = min(d[j],d[j-v[i]] + 1);
            }
        }
    }
    
    if(d[m] == 10001){
        cout << -1 << '\n';
    }
    else{
        cout << d[m] << '\n';
    }
	
	
	return 0;
}
