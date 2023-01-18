/*
PROBLEM STATEMENT:
    - You have two arrays A and B. In one move, you can swap any element of A with any element of B.
    - Find the minimum possible value of max(A) - min(A) that you can attain.


EXPLANATION:
    - let C be an array of size 2n containing all the elements of A and B.
    - Let's sort C, so C1 <= C2 <= ... <= C2n

    - To minimize the difference, it’s clearly optimal to choose N consecutive elements from this sorted C
    - That is, if the smallest element we pick is C[i], then it's optimal to pick the elements
      {Ci, Ci+1, Ci+2, ..., Cn+i-1}; giving us the difference of Cn+i-1 - Ci
      
    - There are n+1 choices for the smallest element: C1, C2, ..., Cn+1
    
 Credit: CodeChef
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin >> n;
        vector<int> C(2*n); // will contain elements of both A and B
        for(int i=0; i<2*n; ++i) cin>>C[i];
        
        sort(C.begin(), C.end());
        
        int ans=1e9;
        for(int i=0; i<=n; ++i) {
            int diff = C[n+i-1] - C[i];
            ans = max(ans, diff);
        }
        cout << ans << '\n';
    }
}
