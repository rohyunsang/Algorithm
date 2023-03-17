#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
vector<int> db;
int ans;
int sum = 0;

int main() {
    cin >> n;
    for(auto i=0;i<n;i++) {
        int nTmp;
        cin >> nTmp;
        db.push_back(nTmp);
    }
    cin>> m;

    sort(db.begin(),db.end());

    int start = 0;
    int end = db[n-1];

    
    while(start<=end) {
        int mid = (start+end)/2;
        for(auto i=0; i<n;i++) {
            sum += min(db[i],mid);
        }
        if(m >= sum) {
            ans = mid;
            start = mid+1;
        }else {
            end = mid-1;
        }
    }

    cout << ans;
}
