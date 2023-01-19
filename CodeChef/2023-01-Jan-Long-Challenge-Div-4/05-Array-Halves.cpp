/*
Problem Code: ARRHALVES
*/

// VERDICT: WA
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int> arr(2*n);
        for(int i=0; i<2*n; ++i) cin>>arr[i];
        
        int ans=0, cnt=0;
        for(int i=0; i<2*n; ++i) {
            if(arr[i]<=n) ans+=cnt;
            else ++cnt;
        }
        cout << ans << '\n';
    }
}
